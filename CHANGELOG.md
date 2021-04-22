# Installation & Update

To install Beacon, see the [documentation](https://developer.helpscout.com/beacon-2/mobile/).

## 2.2.1 Release (April 22, 2021)

##### Bug Fixes
* We now call prefill: on subsequent opens of the contact form in Secure Mode. [Issue 34](https://github.com/helpscout/beacon-ios-sdk/issues/34)
* Beacon now builds successfully when using Xcode 12.5. [Issue 153](https://github.com/helpscout/beacon-ios-sdk/issues/153)

## 2.2.0 Release (January 19, 2021)

##### Features
Customers can now rate their chat experience after completion (for mailboxes with chat satisfaction ratings enabled).

##### Bug Fixes
* We smoothed out the transitions when following a deep link into the app. [Issue 131](https://github.com/helpscout/beacon-ios-sdk/issues/131) 
* We enhanced our color selection logic to ensure all text provides suitable contrast to be easily read. [Issue 139](https://github.com/helpscout/beacon-ios-sdk/issues/139)
* Added tint color override and beacon color override settings to the Beacon Example app. [Issue 143](https://github.com/helpscout/beacon-ios-sdk/issues/143)
* Beacon no longer experiences intermittent crashes when rotating a chat that includes an attachment. 
* Beacon now does a better job of wrapping text. [Issue 83](https://github.com/helpscout/beacon-ios-sdk/issues/83)
* We made the chat back button a bit easier to tap on an iPad. [Issue 133](https://github.com/helpscout/beacon-ios-sdk/issues/133)
* We show previous messages when they are available from the first time Beacon is launched. [Issue 140](https://github.com/helpscout/beacon-ios-sdk/issues/140)
* We restored the ability to print to console when integrating Beacon using SPM. [Issue 145](https://github.com/helpscout/beacon-ios-sdk/issues/145)

## 2.1.2 Release (November 19, 2020)

##### Features
* Customers can now rate articles on the iOS SDK.
* Beacon now attaches sessionAttributes when a customer starts a chat in addition to starting a conversation. [Issue 103](https://github.com/helpscout/beacon-ios-sdk/issues/103)
* Customers can now have anonymous chats if the "Require email?" option in the Beacon config is set to false.

##### Bug Fixes
* Beacon can now be distributed to the App Store when the host application has Bitcode enabled. [Issue 124](https://github.com/helpscout/beacon-ios-sdk/issues/124)
* Beacon no longer crashes when chat agents become unavailable after the customer attempted to start a chat. [Issue 132](https://github.com/helpscout/beacon-ios-sdk/issues/132)

##### Improvements
* You can now integrate Beacon into your project using the Swift Package Manager. [Issue 114](https://github.com/helpscout/beacon-ios-sdk/issues/114)
* [HSBeacon handleWillPresentNotification: completion:] now returns a BOOL to indicate if Beacon called the completionHandler. [Issue 104](https://github.com/helpscout/beacon-ios-sdk/issues/104)

## 2.1.1 Release (November 9, 2020)

##### Features
* Customers now have a similar experience with Beacon on all platforms: web, Android, or iOS. [Issue 67](https://github.com/helpscout/beacon-ios-sdk/issues/67)
* Customizing the [focusMode](https://docs.helpscout.com/article/1296-work-with-beacon-modes) configuration value at the SDK or the Beacon config level allows you to change the SDK's behavior and appearance for your users.
* Beacon now uses the PHPicker when attaching images and videos on iOS 14. Beacon no longer requests permission to the user's photo library when attempting to attach photos or videos. [Issue 119](https://github.com/helpscout/beacon-ios-sdk/issues/119)

##### Bug Fixes
* User attributes are now set for all logged-in users, even if they haven't sent an email. [Issue 115](https://github.com/helpscout/beacon-ios-sdk/issues/115)
* Non-logged-in users are now able to change their email address after sending a message. [Issue 120](https://github.com/helpscout/beacon-ios-sdk/issues/120)
* Selecting the previous conversations button on the sent message screen will now redirect you to the appropriate place. [Issue 108](https://github.com/helpscout/beacon-ios-sdk/issues/108)
* SwiftUI previews now work as we distribute Beacon 2.1.0 as an XCFramework. [Issue 112](https://github.com/helpscout/beacon-ios-sdk/issues/112)
* Users will no longer experience a crash when trying to preview chat attachments on iOS 11 and 12.

##### Deprecations
* `HSBeaconMessagingSettings.showGetInTouch` & `HSBeaconMessagingSettings.showGetInTouchSet` have been deprecated as they're no longer applicable in Beacon 2.1.
* `HSBeacon.login` has been deprecated in favor of `HSBeacon.identify`. The method parameters have not changed, so replacing calls to login with identify is the only necessary change.


## 2.1.0 Release (October 29, 2020) - Removed

We discovered an issue where under some Beacon configurations the Beacon SDK could not be dismissed.  Because of this we have removed 2.1.0 and will resolve those issues before publishing a new release. Please use 2.0.2 in the mean time, thank you for your patience.

## 2.0.2 (September 16, 2020)

##### Bug Fixes
* We no longer show the incorrect email error when pressing the send message button the first time. This resolves the following issues:
  * [Issue 111](https://github.com/helpscout/beacon-ios-sdk/issues/111)
  * [Issue 109](https://github.com/helpscout/beacon-ios-sdk/issues/109)
  * [Issue 94](https://github.com/helpscout/beacon-ios-sdk/issues/94)
* We have addressed the crash observed when attempting to add a video from your camera roll to an in-progress chat session. ([Issue 100](https://github.com/helpscout/beacon-ios-sdk/issues/100))
* Beacon now respects the messaging setting allowAttachments in both the contact form and chat. ([Issue 101](https://github.com/helpscout/beacon-ios-sdk/issues/101))
* We have fixed the crash caused by suggesting articles to a user with a previously opened Beacon.  ([Issue 102](https://github.com/helpscout/beacon-ios-sdk/issues/102))
* We have remediated a threading violation when minimizing an active chat.  ([Issue 105](https://github.com/helpscout/beacon-ios-sdk/issues/105))

## 2.0.1 (August 31, 2020)

##### Bug Fixes
* We have addressed the unwanted navigation color change issues. ([Issue 85](https://github.com/helpscout/beacon-ios-sdk/issues/85) & [Issue 73](https://github.com/helpscout/beacon-ios-sdk/issues/73)))
* If `emailTranscriptionEnabled` is false, we won't display a message saying we will send your chat transcript to you in an email when the chat ends. ([Issue 87](https://github.com/helpscout/beacon-ios-sdk/issues/87))).
* If `enablePreviousMessages` is set to false on your `HSBeaconSettings` object, Beacon will no longer display a message about viewing previous conversations when a chat ends.
* Beacon will now notify the `HSBeaconDelegate` when it was closed due to being swiped away on iOS 13+.  ([Issue 88](https://github.com/helpscout/beacon-ios-sdk/issues/88)))
* Beacon will present push notifications for conversation replies while the user has your app in the foreground.
* `HSBeaconSettings` now has a single designated initializer that takes the Beacon ID to prevent problems down the line.

## 2.0.0 (August 17, 2020)

##### Features
* Live chat - Customers can now start a chat within your app on their iOS device, accessing great support no matter where they are.
* We have added support for session attributes. ([Issue 70](https://github.com/helpscout/beacon-ios-sdk/issues/70))
##### Bug Fixes
* Custom Suggestion URLs no longer crash when tapped on iPad. ([Issue 59](https://github.com/helpscout/beacon-ios-sdk/issues/59))
* Users can now continue to the next field in the contact form by using the return key. ([Issue 69](https://github.com/helpscout/beacon-ios-sdk/issues/69))
* We no longer duplicate prefilled attachments on subsequent presentations of the contact form. ([Issue 68](https://github.com/helpscout/beacon-ios-sdk/issues/68))
* Email-only Beacons will now go straight to the contact form instead of an intermediary screen. ([Issue 74](https://github.com/helpscout/beacon-ios-sdk/issues/74))
* We now build the Beacon SDK as a library for distribution. ([Issue 75](https://github.com/helpscout/beacon-ios-sdk/issues/75)) & ([Issue 78](https://github.com/helpscout/beacon-ios-sdk/issues/78)) 
* The 'Send a Message' screen now properly uses localization overrides from the Beacon Web UI. ([Issue 79](https://github.com/helpscout/beacon-ios-sdk/issues/79))
* We have removed all external dependencies. ([Issue 60](https://github.com/helpscout/beacon-ios-sdk/issues/60))

## 2.0.0 Beta 2 Release (May 26, 2020)

##### Bug Fixes

* Many bugs with the new Chat feature have been fixed.

## 2.0.0 Beta 1 Release (April 16, 2020)

##### Enhancements

* Live chat - Now customers can start a chat from your app on their iOS device, accessing great support no matter where they are.

## 1.0.5 Release (March 13, 2020)

##### Bug Fixes

* Fixed the root cause of [issue 40](https://github.com/helpscout/beacon-ios-sdk/issues/40) where the Reply modal was not presented when attempting to respond via your Conversation history
* Push notifications will now successfully register for any messages delivered across all iOS versions

## 1.0.4 Release (March 5, 2020)

##### Bug Fixes

* Attachments can now be added to replies from the previous messages screen on iPad ([Issue 52](https://github.com/helpscout/beacon-ios-sdk/issues/52))
* Update our use of UIWebView to WKWebView ([Issue 37](https://github.com/helpscout/beacon-ios-sdk/issues/37))
* Improved error messaging in cases where we failed to load the Beacon configuration ([Issue 38](https://github.com/helpscout/beacon-ios-sdk/issues/38))
* Chat replies are now presented ([Issue 40](https://github.com/helpscout/beacon-ios-sdk/issues/40))

## 1.0.3 Release (January 8, 2020)

##### Bug Fixes

* Prevent the prefill method from being called multiple times ([Issue 42](https://github.com/helpscout/beacon-ios-sdk/issues/42))
* Dismissing Beacon now prompts the user correctly on iOS 13 ([Issue 43](https://github.com/helpscout/beacon-ios-sdk/issues/43))
* Fixed image picker warnings on the main thread ([Issue 46](https://github.com/helpscout/beacon-ios-sdk/issues/46))
* Text prefill does not prevent message submission ([Issue 47](https://github.com/helpscout/beacon-ios-sdk/issues/47))

## 1.0.2 Release (November 14, 2019)

##### Bug Fixes

* Fixes a crash reported in HSBeaconPreviousMessagesController. ([Issue 33](https://github.com/helpscout/beacon-ios-sdk/issues/33))
* Improves prefill behavior when opening a contact form subsequent times. ([Issue 34](https://github.com/helpscout/beacon-ios-sdk/issues/34))
* Fixes a crash when calling reset on a form with attachments. ([Issue 35](https://github.com/helpscout/beacon-ios-sdk/issues/35))
* Fixes not being able to select an image from the Photo Library on iOS 13. ([Issue 39](https://github.com/helpscout/beacon-ios-sdk/issues/39) & [Issue 41](https://github.com/helpscout/beacon-ios-sdk/issues/41))
* Fixes an issue that prevented some apps from supporting dark mode. ([Issue 32](https://github.com/helpscout/beacon-ios-sdk/issues/32))

## 1.0.1 Release (May 23, 2019)

##### Enhancements

* Added a `tintColorOverride` setting to allow for customization of the color of buttons and labels throughout the SDK

##### Bug Fixes

* Fixes for the Get In Touch & Messaging Enabled settings
* Fixes for CSS issues with nested `ol` tags

## 1.0.0 Release (March 15, 2019)

* New `reset` method on `HSBeacon` to clear the current state
* New `suggestWithItems` method that also allows for URL-based custom suggestions
* New `HSBeaconDelegate` methods for intercepting Beacon open and close events
* Improved VoiceOver support - translations for button accessibility labels and the navigation tabs now respond correctly in VoiceOver mode
* The `HSBeaconSettings` object is now available on the `HSBeaconContactForm` object when calling `prefill`.
* Fixes for layout bugs on iPad where UI elements would render offscreen.
* The `color` attribute of `HSBeaconSettings` is now a strong reference.
* The name and email fields are now always shown on the contact form unless the `login` method is called. This allows users who have manually entered these values to correct mistakes when sending a new email.

## 1.0.0 beta (build 73) (January 16, 2019)

* We've fixed the message history for secure mode users that broke in build 0.69. Sorry for the trouble!

## 1.0.0 beta (build 72) (December 19, 2018)

##### Enhancements

* Added a new method `suggest` for custom suggestions
* Added `dismissBeacon` method to make sure Beacon isn't in the way of other code in your app
* Carthage support is back!
* A continued restructuring of [our developer documentation](https://developer.helpscout.com/beacon-2/ios/)

## 1.0.0 beta (build 71) (December 7, 2018)

##### Bug Fixes

* The main Beacon controller now implements `preferredStatusBarStyle` to try to resolve [issue #19](https://github.com/helpscout/beacon-ios-sdk/issues/19)
* Article viewed activities will now link to the article in you Help Scout Beacon note, rather than the application in the App Store. Search activities will no longer show a link. This also resolves a crash with a missing `CFBundleName`. Long term, we'll add the Beacon name & platform to the note so you can more easily identify the source.

## 1.0.0 beta (build 69) (December 6, 2018)

##### Bug Fixes

* Fixed user attribute upload for unsecure users
* Fixed a crash condition with the `navigate` method

## 1.0.0 beta (build 67) (November 27, 2018)

##### Enhancements

* New methods on `HSBeacon` - `search`, `openArticle`, and `navigate`.
* Our developer site now includes [Jazzy](https://github.com/realm/jazzy) generated API documentation.

##### Bug Fixes

* More translation fixes documented [here](https://github.com/helpscout/beacon-ios-sdk/issues/8#issuecomment-434243479) and [here](https://github.com/helpscout/beacon-ios-sdk/pull/11/files).


## 1.0.0 beta (build 58) (October 24, 2018)

##### Bug Fixes

* The text for "We usually respond in..." was not getting translated with the `useLocalTranslationOverrides` option enabled ([reported issue](https://github.com/helpscout/beacon-ios-sdk/issues/8))


## 1.0.0 beta (build 57) (October 23, 2018)

##### Enhancements

* New local overrides added to `HSBeaconSettings`
  * Color
  * Docs enabled
  * Custom fields enabled
  * Show name
  * Show subject
  * Allow attachments
  * Show get in touch
  * Show prefilled custom fields
* User attribute limit increased to 30
* Attachment preview now uses QuickLook instead of `UIDocumentInteractionController` to address App Store rejections

##### Bug Fixes

* Status bar color is restored when exiting Beacon

## 1.0.0 beta (build 52) (September 21, 2018)

##### Bug Fixes

* Fixed a crash on previous messages with an empty subject reported [here](https://github.com/helpscout/beacon-ios-sdk/issues/6)

## 1.0.0 beta (build 49) (September 19, 2018)

##### Enhancements

* Added a flag for disabling the contact form
* Added a blank state in cases where Docs and Messaging are both disabled
* UI enhancements related to overlapping & loading content

##### Bug Fixes

* Dynamic Type will no longer need an app restart to take effect
* Fixed scrolling issues for articles with large tables

## 1.0.0 beta (build 44) (August 7, 2018)

##### Enhancements

* Beacon is now distributed as a static framework
* Added up & down arrows to navigate between form fields
* Custom fields and agent avatars are now cached between loads
* Dynamic Type is supported in multiple areas
* Form field length limits are now more tightly enforced
* The contact form can now be prefilled to provide attachments and field values automatically

##### Bug Fixes

* Fix a case where related article links would not always work from search
* Ensure that the search results back button will adhere to the Beacon color

## 1.0.0 beta (build 41) (July 17, 2018)

##### Enhancements

* Added state restoring when opening the same Beacon after it has been closed
* Improvements to network error handling
* Updated the visual appearance of custom fields
* Updated the contact button when viewing empty search results

##### Bug Fixes

* Fixed crashes around attachment uploading
* Fixed articles failing to load correctly

## 1.0.0 beta (build 37) (June 18, 2018)

##### Enhancements

* Improve error handling in the Previous Messages flow
* Prevent sending duplicate messages when replying to a thread or starting a new one

##### Bug Fixes

* Attachments with zero length are now rejected

## 1.0.0 beta (build 36) (June 13, 2018)

##### Enhancements

* Use `WKWebView` for rendering articles

##### Bug Fixes

* Fix an issue with article cards where the status bar would overlap the article
* Fix an issue where the article content may never appear after loading

## 1.0.0 beta (build 35) (June 12, 2018)

##### Enhancements

* Initial framework release

##### Bug Fixes

* Initial framework release
