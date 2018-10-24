
**The Beacon SDK is currently in beta. For issues or questions, contact Help Scout support at help@helpscout.com.**

## Requirements

The Beacon SDK requires iOS 9.0+.

## Features

### Coming Soon

* Beacon chat
* Push notification support

## Installation

### CocoaPods

Beacon is available through [CocoaPods][1]. To install it, simply add the following line to your `Podfile`:

```ruby
pod 'Beacon'
```

### Carthage

Beacon can be installed using Carthage by adding the following line to your `Cartfile` and then following the [Carthage installation instructions][2]:

```ruby
github "helpscout/beacon-ios-sdk"
```

## Additional Setup

### Photos

The attachments menu for sending a message has code to allow users to take a photo or select a photo from their photo library. Even if you have attachments disabled, usage of these APIs is flagged by Apple and requires a description string in the app's `Info.plist` file.

The required settings are `NSPhotoLibraryUsageDescription` and `NSCameraUsageDescription`:

<img src="https://github.com/helpscout/HSAttachmentPicker/raw/master/picker_photos_permissions.png" width="650" height="376">

### Documents

To access the documents picker in the attachment menu, you'll need the entitlements for iCloud and iCloud Containers. Without the entitlements, an error message will be thrown via the delegate on the 'Import file from' menu option.

<img src="https://github.com/helpscout/HSAttachmentPicker/raw/master/picker_icloud_permissions.png" width="856" height="346">

### Push Notifications

You may recieve a warning when uploading to App Store connect related to push notifications if they aren't already active in your application. Similar to Photos, App Store Connect will flag usage of these APIs in code even if they aren't invoked in the app.

The notification feature is still under construction for the Beacon SDK.

## Usage

You can find basic setup code and your Beacon ID in the web Beacon builder by clicking "Installation" on the left sidebar, then navigating to "iOS" in the options displayed at the top.

Basic usage of the Beacon SDK requires an `HSBeaconSettings` object, which can be initialized using your Beacon ID. After you have created a settings object, you can display the Beacon modal view controller via `HSBeacon`:

##### Objective-C

```objc
HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon openBeacon:settings];
```

##### Swift

```swift
let settings = HSBeaconSettings(beaconId: "beacon-id")
HSBeacon.open(settings)
```

## Authenticating Users

You can provide the name and email address to pre-populate and hide the fields on the ‘Create a message’ screen.

##### Objective-C

```objc
HSBeaconUser *user = [[HSBeaconUser alloc] init];
user.email = "test@example.com"
user.name = "Test User";

[HSBeacon login:user];

HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon openBeacon:settings];
```

##### Swift

```swift
let user = HSBeaconUser()
user.email = "test@example.com"
user.name = "Test User";

HSBeacon.login(user)

let settings = HSBeaconSettings(beaconId: "123")
HSBeacon.open(settings)
```

### Secure Mode

If a valid signature is provided, it can be used to authenticate a user in [Secure Mode](https://developer.helpscout.com/beacon-2/web/secure-mode/) and retrieve their previous conversations. Secure Mode ensures that the visitor is who they say they are.

> Note: the secret key should *not* be stored in the app; instead your server should provide the computed signature value.

##### Objective-C

```objc
HSBeaconUser *user = [[HSBeaconUser alloc] init];
user.email = @"test@example.com";
[HSBeacon login:user];

HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon openBeacon:settings signature:@"8235545a15c6f41b64e3c47e5c94d3..."];
```

##### Swift

```swift
let user = HSBeaconUser()
user.email = "test@example.com"
HSBeacon.login(user)

let settings = HSBeaconSettings(beaconId: "beacon-id")
HSBeacon.open(settings, signature: "8235545a15c6f41b64e3c47e5c94d3...")
```

## User Attributes

`HSBeaconUser` supports the addition of up to 30 attributes. These are arbitrary key-value pairs used to track custom data attributes that are then synced with the customer’s Help Scout profile and displayed in the Beacon Sidebar app. You can add as many attributes to the ‘identify’ method as you wish, not just “name’ and “email”.

Here's some example code:

##### Objective-C

```objc
HSBeaconUser *user = [[HSBeaconUser alloc] init];
[user addAttributeWithKey:@"key" value:@"attribute value"];
```

##### Swift

```swift
let user = HSBeaconUser()
user.addAttribute(withKey: "key", value: "attribute value")
```

You may also remove specific attributes, or clear the entire set:

##### Objective-C

```objc
HSBeaconUser *user = [[HSBeaconUser alloc] init];
[user removeAttributeWithKey:@"key"]; // Remove one attribute
[user clearAttributes]; // Clear all attributes
```

##### Swift

```swift
let user = HSBeaconUser()
user.removeAttribute(withKey: "key") // Remove one attribute
user.clearAttributes() // Clear all attributes
```

## Prefilling the contact form

By implementing the `prefill` method on the `HSBeaconDelegate` protocol, you can pre-populate the contact form data.  You can fill any of the fields: name, email, subject, the body of the message (text), custom fields, and attachments. Unlike when using secure mode, the name and email fields will remain visible and editable.

The `delegate` attribute of the settings object will need to be set to the instance implementing the `HSBeaconDelegate` protocol.


##### Objective-C

```objc
# pragma mark HSBeaconDelegate
-(void)prefill:(HSBeaconContactForm *)form {
    form.name = @"Steve Aoki";
    form.email = @"steve@aoki.com";
    form.subject = @"Need help with invoice";
    form.text = @"Hello, I need some help with my invoice. See attached PDF...";
    [form addCustomFieldValue: @"Question" forId: 5678];
    NSData *invoiceData = [NSData dataWithContentsOfFile:@"/path/to/invoice.pdf"];
    [form addAttachment: @"invoice.pdf" data:invoiceData];
}
```

##### Swift

```swift
extension ViewController: HSBeaconDelegate {
    func prefill(_ form: HSBeaconContactForm) {
        form.name = "Steve Aoki"
        form.email = "steve@aoki.com"
        form.subject = "Need help with invoice"
        form.text = "Hello, I need some help with my invoice. See attached PDF..."
        form.addCustomFieldValue("Question", forId: 5678)
        let invoiceData = try! Data(contentsOf: URL(fileURLWithPath: "/path/to/invoice.pdf"))
        form.addAttachment("invoice.pdf", data: invoiceData)
    }
}
```

## Settings customization

You can set various options on the `HSBeaconSettings` object to override the Beacon Builder configuration.

<table>
  <tr>
    <th>Name</th>
    <th>Type</th>
    <th>Description</th>
  </tr>
  <tr>
    <td><pre>messagingEnabled</pre></td>
    <td>Bool</td>
    <td>Enable or disable the contact options</td>
  </tr>
  <tr>
    <td><pre>docsEnabled</pre></td>
    <td>Bool</td>
    <td>Enable or disable the Docs integration</td>
  </tr>
  <tr>
    <td><pre>beaconTitle</pre></td>
    <td>String</td>
    <td>The navigation title shown on the intial Beacon screen (only if docs is enabled); the default is "Support".</td>
  </tr>
  <tr>
    <td><pre>useNavigationBarAppearance</pre></td>
    <td>Bool</td>
    <td>If this is true, then Beacon will use tint colors defined via `UIAppearance` providing they are not nil; otherwise it will use the Beacon color</td>
  </tr>
  <tr>
    <td><pre>color</pre></td>
    <td>UIColor</td>
    <td>Brand color for your Beacon; the `useNavigationBarAppearance` option will override this value.</td>
  </tr>
  <tr>
    <td><pre>useLocalTranslationOverrides</pre></td>
    <td>Bool</td>
    <td>You may customize the user-facing strings in Beacon locally using `HSBeaconSettings`. This will tell Beacon to look for a `BeaconLocalizable.strings` file. You can find an example of this <a href="https://github.com/helpscout/beacon-ios-sdk/blob/master/Example/Beacon/BeaconLocalizable.strings">in the Beacon Example app</a>. If this flag isn't set, the translations provided in Beacon Builder will be used.
    </td>
  </tr>
  <tr>
    <td><pre>messagingSettings</pre></td>
    <td>HSBeaconMessagingSettings</td>
    <td>This object holds a number of messaging specific overrides you can set client side; see below for a list of values
    </td>
  </tr>
</table>

### Messaging Settings object

<table>
  <tr>
    <th>Name</th>
    <th>Type</th>
    <th>Description</th>
  </tr>
  <tr>
    <td><pre>contactFormCustomFieldsEnabled</pre></td>
    <td>Bool</td>
    <td>Enable or disable Custom Fields</td>
  </tr>
  <tr>
    <td><pre>contactFormShowNameField</pre></td>
    <td>Bool</td>
    <td>Display an editable Name field</td>
  </tr>
  <tr>
    <td><pre>contactFormShowSubjectField</pre></td>
    <td>Bool</td>
    <td>Display an editable Subject field</td>
  </tr>
  <tr>
    <td><pre>contactFormAllowAttachments</pre></td>
    <td>Bool</td>
    <td>Enable or disable file attachments</td>
  </tr>
  <tr>
    <td><pre>showGetInTouch</pre></td>
    <td>Bool</td>
    <td>Show a contact link on the Beacon home screen</td>
  </tr>
  <tr>
    <td><pre>showPrefilledCustomFields</pre></td>
    <td>Bool</td>
    <td>Show a contact link on the Beacon home screen</td>
  </tr>
</table>

## Running The Example App

To run the example project, clone the Beacon repo and run `pod install` from the Example directory. Once the installation is complete, open `Beacon Example.xcworkspace` and run the `Beacon Example` scheme.

## Useful Links

* [Changelog](https://github.com/helpscout/beacon-ios-sdk/blob/master/CHANGELOG.md) – get a list of recent changes to the Beacon SDK

[1]:	http://cocoapods.org
[2]:	https://github.com/Carthage/Carthage#adding-frameworks-to-an-application
