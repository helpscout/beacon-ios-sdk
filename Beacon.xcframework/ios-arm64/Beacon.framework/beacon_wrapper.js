/**
 * Beacon iOS SDK JavaScript Wrapper
 * 
 * This file provides a simple interface between the Beacon JavaScript SDK and the iOS native layer.
 */

(function () {
    'use strict';

    // =============================================================================
    // CORE UTILITIES
    // =============================================================================
    
    /**
     * Helper function to communicate with native layer
     * @param {string} type - The message type
     * @param {string} info - The message payload
     */
    function callNative(type, info) {
        try {
            window.webkit.messageHandlers.iOS.postMessage({
                type: type,
                info: info
            });
        } catch (e) {
            console.error('Error calling native:', e);
        }
    }

    // =============================================================================
    // CONSOLE INTERCEPTION - Forward console messages to native layer for debugging
    // =============================================================================

    /**
     * Store original console methods before overriding
     */
    const originalConsole = {
        log: console.log,
        error: console.error,
        warn: console.warn,
        info: console.info
    };

    /**
     * Override console.log to forward to native layer
     */
    console.log = function(...args) {
        try {
            callNative("onConsoleLog", JSON.stringify(args));
        } catch (e) {
            originalConsole.error('Error forwarding console.log:', e);
        }
        originalConsole.log.apply(console, args);
    };

    /**
     * Override console.error to forward to native layer
     */
    console.error = function(...args) {
        try {
            callNative("onConsoleError", JSON.stringify(args));
        } catch (e) {
            originalConsole.error('Error forwarding console.error:', e);
        }
        originalConsole.error.apply(console, args);
    };

    /**
     * Override console.warn to forward to native layer
     */
    console.warn = function(...args) {
        try {
            callNative("onConsoleWarn", JSON.stringify(args));
        } catch (e) {
            originalConsole.error('Error forwarding console.warn:', e);
        }
        originalConsole.warn.apply(console, args);
    };

    /**
     * Override console.info to forward to native layer
     */
    console.info = function(...args) {
        try {
            callNative("onConsoleInfo", JSON.stringify(args));
        } catch (e) {
            originalConsole.error('Error forwarding console.info:', e);
        }
        originalConsole.info.apply(console, args);
    };

    // =============================================================================
    // WEB STORAGE CLEANUP
    // =============================================================================

    const BEACON_STORAGE_KEY_PREFIXES = ['persist:hs-beacon-', 'hs-beacon-'];

    function removeBeaconKeys(storage) {
        const keys = [];
        for (let i = 0; i < storage.length; i++) {
            keys.push(storage.key(i));
        }
        keys.filter(key => BEACON_STORAGE_KEY_PREFIXES.some(prefix => key.startsWith(prefix)))
            .forEach(key => storage.removeItem(key));
    }

    // =============================================================================
    // BEACON SDK INTEGRATION
    // =============================================================================
    
    const BeaconSDK = {
        // Track if event listeners have been registered
        listenersRegistered: false,
        currentBeaconId: null,
        clearedWebStorageId: null,

        /**
         * Remove the previous Beacon's data from the web storage before Beacon JS reads it, then let iOS know.
         * A clear ID is applied once per page, so a repeated init doesn't remove the new Beacon's data.
         * A failed clear isn't acknowledged, so iOS keeps it pending and the next init retries it.
         * @param {string} clearId - The ID of the clear iOS asked for
         */
        clearWebStorage: function(clearId) {
            try {
                if (this.clearedWebStorageId !== clearId) {
                    removeBeaconKeys(window.localStorage);
                    removeBeaconKeys(window.sessionStorage);
                    this.clearedWebStorageId = clearId;
                }
                callNative("onWebStorageCleared", clearId);
            } catch (e) {
                console.error('Failed to clear web storage:', e);
            }
        },

        /**
         * Load the Beacon script and notify iOS when ready
         */
        loadScript: function() {
            (function (e, t, n) {
                function a() {
                    var e = t.getElementsByTagName("script")[0],
                        n = t.createElement("script");
                    n.type = "text/javascript";
                    n.async = true;
                    n.src = "https://beacon-v2.helpscout.net";
                    n.onload = function () {
                        callNative("onBeaconSdkLoaded");
                    };
                    e.parentNode.insertBefore(n, e);
                }

                if (e.Beacon = n = function (t, n, a) {
                    e.Beacon.readyQueue.push({method: t, options: n, data: a});
                }, n.readyQueue = [], "complete" === t.readyState) return a();
                e.attachEvent ? e.attachEvent("onload", a) : e.addEventListener("load", a, false);
            })(window, document, window.Beacon || function () {});
        },

        /**
         * Initialize Beacon.
         * Accepts either a beaconId string (legacy) or an options object:
         *   { beaconId: '...', deviceId: '...', webStorageClearId: '...' }
         *
         * @param {string|object} initArg - The Beacon ID (string) or init options (object)
         */
        init: function(initArg) {
            const isObject = initArg && typeof initArg === 'object';
            const beaconId = isObject ? initArg.beaconId : initArg;
            const deviceId = isObject ? initArg.deviceId : null;
            const webStorageClearId = isObject ? initArg.webStorageClearId : null;

            if (webStorageClearId && typeof webStorageClearId === 'string') {
                this.clearWebStorage(webStorageClearId);
            }

            // If beacon ID changed, we need to reset listeners
            if (this.currentBeaconId && this.currentBeaconId !== beaconId) {
                this.listenersRegistered = false;
            }

            this.currentBeaconId = beaconId;

            // Only register event listeners once per beacon ID
            if (!this.listenersRegistered) {
                window.Beacon('on', 'open', function() {
                    callNative("onBeaconOpened");
                });

                window.Beacon('on', 'close', function() {
                    callNative("onBeaconClosed");
                });

                window.Beacon('on', 'ready', function() {
                    callNative("onBeaconReady");
                });

                window.Beacon('on', 'email-sent', function(data) {
                    try {
                        var payload = {
                            conversationId: data && data.conversationId,
                            email: data && data.email,
                            name: data && data.name
                        };
                        callNative("onEmailSent", JSON.stringify(payload));
                    } catch (e) {
                        console.error('Failed to forward email-sent event', e);
                    }
                });

                window.Beacon('on', 'chat-started', function(data) {
                    try {
                        var payload = {
                            chatId: data && data.chatId,
                            email: data && data.email,
                            name: data && data.name,
                            subject: data && data.subject
                        };
                        callNative("onChatStarted", JSON.stringify(payload));
                    } catch (e) {
                        console.error('Failed to forward chat-started event', e);
                    }
                });
                
                this.listenersRegistered = true;
            }

            // Initialize Beacon. If deviceId is available, pass it so the Web SDK can include it
            // in chat creation for push subscription.
            if (deviceId && typeof deviceId === 'string' && deviceId.length > 0) {
                window.Beacon('init', { beaconId: beaconId, deviceId: deviceId });
            } else {
                window.Beacon('init', beaconId);
            }

            // Configure beacon for mobile: disable messages and hide FAB on mobile
            // Messages functionality is not yet supported on the mobile SDK
            window.Beacon('config', {
                'disableMessages': true,
                'hideFABLabelOnMobile': true,
                'hideFABOnMobile': true
            });
        },

        /**
         * Open the beacon
         */
        open: function() {
            if (window.Beacon) {
                window.Beacon('open');
            }
        },

        /**
         * Close the beacon
         */
        close: function() {
            if (window.Beacon) {
                window.Beacon('close');
            }
        },

        /**
         * Navigate to a specific route
         * @param {string} route - The route to navigate to
         */
        navigate: function(route) {
            if (window.Beacon) {
                window.Beacon('navigate', route);
            }
        },

        /**
         * Perform a search
         * @param {string} query - The search query
         */
        search: function(query) {
            if (window.Beacon) {
                window.Beacon('search', query);
            }
        },

        /**
         * Get beacon info and send to iOS
         */
        getInfo: function() {
            if (window.Beacon) {
                const info = window.Beacon('info');
                callNative("onBeaconInfo", JSON.stringify(info));
            }
        },

        /**
         * Attempt to navigate back inside the Beacon UI.
         * Searches the main document first, then the #beacon-container iframe.
         * @returns {boolean} true if a back button was found and clicked; false otherwise
         */
        navigateBack: function() {
            try {
                const tryClickBack = function(doc) {
                    if (!doc) {
                        return false;
                    }
                    const backButton = doc.querySelector('a.c-HeaderNavLink.is-back');
                    if (backButton) {
                        backButton.click();
                        return true;
                    }
                    return false;
                };

                // Try main document
                if (tryClickBack(document)) {
                    return true;
                }

                // Try iframe inside beacon container
                const iframe = document.querySelector('#beacon-container iframe');
                if (iframe) {
                    const iframeDoc = iframe.contentDocument || (iframe.contentWindow && iframe.contentWindow.document);
                    if (tryClickBack(iframeDoc)) {
                        return true;
                    }
                }
            } catch (e) {
                console.error('navigateBack error:', e);
            }
            return false;
        }
    };

    // =============================================================================
    // FILE CREATION HELPERS
    // =============================================================================
    
    /**
     * Creates a File object from base64-encoded data
     * @param {string} base64 - Base64-encoded file content
     * @param {string} name - Filename
     * @param {string} type - MIME type (e.g., "image/jpeg", "application/pdf")
     * @returns {File|null} A File object ready for use in Beacon prefill API, or null if creation fails
     */
    window.beaconCreateFileFromBase64 = function(base64, name, type) {
        try {
            const binary = atob(base64);
            const bytes = new Uint8Array(binary.length);
            for (let i = 0; i < binary.length; i++) {
                bytes[i] = binary.charCodeAt(i);
            }
            return new File([bytes], name, { type: type });
        } catch (e) {
            console.error('beaconCreateFileFromBase64 failed for file "' + name + '":', e.message);
            return null;
        }
    };

    // =============================================================================
    // PUBLIC API - Functions exposed to native layer
    // =============================================================================
    
    // Initialize the SDK
    BeaconSDK.loadScript();
    
    // Expose functions to native layer
    // Supports either: window.initBeacon('beacon-id') OR window.initBeacon({ beaconId, deviceId, webStorageClearId })
    window.initBeacon = function(initArg) { return BeaconSDK.init(initArg); };
    window.openBeacon = function() { return BeaconSDK.open(); };
    window.closeBeacon = function() { return BeaconSDK.close(); };
    window.navigateBeacon = function(route) { return BeaconSDK.navigate(route); };
    window.searchBeacon = function(query) { return BeaconSDK.search(query); };
    window.getBeaconInfo = function() { return BeaconSDK.getInfo(); };
    window.navigateBeaconBack = function() { return BeaconSDK.navigateBack(); };

})(); 
