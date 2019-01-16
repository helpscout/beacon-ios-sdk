# Installation & Update

To install Beacon, see the [documentation](https://developer.helpscout.com/beacon-2/).

## 1.0.0 beta (build 73)

* We've fixed the message history for secure mode users that broke in build 0.69. Sorry for the trouble!

## 1.0.0 beta (build 72)

##### Enhancements

* Added a new method `suggest` for custom suggestions 
* Added `dismissBeacon` method to make sure Beacon isn't in the way of other code in your app
* Carthage support is back!
* A continued restructuring of [our developer documentation](https://developer.helpscout.com/beacon-2/ios/)

## 1.0.0 beta (build 71)

##### Bug Fixes

* The main Beacon controller now implements `preferredStatusBarStyle` to try to resolve [issue #19](https://github.com/helpscout/beacon-ios-sdk/issues/19)
* Article viewed activities will now link to the article in you Help Scout Beacon note, rather than the application in the App Store. Search activities will no longer show a link. This also resolves a crash with a missing `CFBundleName`. Long term, we'll add the Beacon name & platform to the note so you can more easily identify the source.

## 1.0.0 beta (build 69)

##### Bug Fixes

* Fixed user attribute upload for unsecure users
* Fixed a crash condition with the `navigate` method

## 1.0.0 beta (build 67)

##### Enhancements

* New methods on `HSBeacon` - `search`, `openArticle`, and `navigate`.
* Our developer site now includes [Jazzy](https://github.com/realm/jazzy) generated API documentation.

##### Bug Fixes

* More translation fixes documented [here](https://github.com/helpscout/beacon-ios-sdk/issues/8#issuecomment-434243479) and [here](https://github.com/helpscout/beacon-ios-sdk/pull/11/files).


## 1.0.0 beta (build 58)

##### Bug Fixes

* The text for "We usually respond in..." was not getting translated with the `useLocalTranslationOverrides` option enabled ([reported issue](https://github.com/helpscout/beacon-ios-sdk/issues/8))


## 1.0.0 beta (build 57)

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


## 1.0.0 beta (build 52)

##### Bug Fixes

* Fixed a crash on previous messages with an empty subject reported [here](https://github.com/helpscout/beacon-ios-sdk/issues/6)

## 1.0.0 beta (build 49)

##### Enhancements

* Added a flag for disabling the contact form
* Added a blank state in cases where Docs and Messaging are both disabled
* UI enhancements related to overlapping & loading content

##### Bug Fixes

* Dynamic Type will no longer need an app restart to take effect
* Fixed scrolling issues for articles with large tables

## 1.0.0 beta (build 44)

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

## 1.0.0 beta (build 41)

##### Enhancements

* Added state restoring when opening the same Beacon after it has been closed
* Improvements to network error handling
* Updated the visual appearance of custom fields
* Updated the contact button when viewing empty search results

##### Bug Fixes

* Fixed crashes around attachment uploading
* Fixed articles failing to load correctly

## 1.0.0 beta (build 37)

##### Enhancements

* Improve error handling in the Previous Messages flow
* Prevent sending duplicate messages when replying to a thread or starting a new one

##### Bug Fixes

* Attachments with zero length are now rejected

## 1.0.0 beta (build 36)

##### Enhancements

* Use `WKWebView` for rendering articles

##### Bug Fixes

* Fix an issue with article cards where the status bar would overlap the article
* Fix an issue where the article content may never appear after loading

## 1.0.0 beta (build 35)

##### Enhancements

* Initial framework release

##### Bug Fixes

* Initial framework release

