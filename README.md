**The Beacon SDK is currently in beta. For issues or questions, contact Help Scout support at help@helpscout.com.**

API documentation is available [here](https://developer.helpscout.com/beacon-2/ios-api/index.html).

## Requirements

The Beacon SDK requires iOS 9.0+.

## Features

### Coming Soon

* Beacon chat
* Push notification support

## Sample Application

We've created an <a href="https://github.com/helpscout/beacon-ios-sdk/tree/master/Example" target="_blank">open source example application</a> that you can reference during your implementation.

To run the example project, clone the Beacon repo and open `Beacon Example.xcodeproj` in the Example directory. This project uses the `Beacon.framework` included in this repo, so you should be able to run the project out of the box.

## Installation

### CocoaPods

Beacon is available through [CocoaPods][1]. To install it, simply add the following line to your `Podfile`:

```ruby
pod 'Beacon'
```

### Manually

Beacon can be installed manually by linking the Beacon framework and bundle. To do so, download the Beacon framework from this GitHub repo and integrate it similar to [how Carthage integrates frameworks](https://github.com/Carthage/Carthage#adding-frameworks-to-an-application).

Next, ensure your project is linking against the following system frameworks:

* `UIKit`
* `Foundation`
* `MobileCoreServices`
* `Photos`
* `QuickLook`
* `SafariServices`
* `UserNotifications`
* `WebKit`

Finally, ensure your project includes `-all_load` in its `OTHER_LINKER_FLAGS` build setting.

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

`HSBeaconUser` supports the addition of up to 10 attributes. These are arbitrary key-value pairs used to track custom data attributes that are then synced with the customer’s profile in Help Scout and displayed in the Beacon Sidebar app. You can add as many attributes to the ‘identify’ method as you wish, not just “name’ and “email”.

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

By implementing the `prefill` method on the `HSBeaconDelegate` protocol, you can pre-populate the contact form data.  You can fill any of the fields: `name`, `email`, `subject`, the body of the message (`text`), custom fields, and attachments. Unlike when using secure mode, the name and email fields will remain visible and editable.

For how to determine the ids for custom field population, see [this documentation](https://trello.com/c/fE9U751Y/386-missing-translations) for the Beacon web component.

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

## Opening with search results

The `HSBeacon search` method searches Docs articles and loads the results screen.

##### Objective-C

```objc
HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon search:@"hippa" beaconSettings: settings];
```

##### Swift

```swift
let settings = HSBeaconSettings(beaconId: "beacon-id")
HSBeacon.search("hipaa", beaconSettings: settings)
```

## Opening to an article

You can use the `HSBeacon openArticle` method to open a specific Docs article within Beacon, using the article's ID. 

Article IDs can be found in Help Scout by navigating to the article and copying the article ID from the URL. The URL is structured like this: `https://secure.helpscout.net/docs/[COLLECTION ID]/article/[ARTICLE ID]/`.

##### Objective-C

```objc
HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon openArticle:@"DOCS_ARTICLE_ID" beaconSettings: settings];
```

##### Swift

```swift
let settings = HSBeaconSettings(beaconId: "beacon-id")
HSBeacon.openArticle("DOCS_ARTICLE_ID", beaconSettings: settings)
```

## Navigation

The `HSBeacon navigate` method opens the Beacon and shows a specific screen. Available routes are:

```objc
HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
[HSBeacon navigate:@"/" beaconSettings: settings]; // welcome screen
[HSBeacon navigate:@"/ask/message/" beaconSettings: settings]; // message screen
[HSBeacon navigate:@"/docs/search?query=help" beaconSettings: settings]; // equivalent to HSBeacon search
```

##### Swift

```swift
let settings = HSBeaconSettings(beaconId: "beacon-id")
HSBeacon.navigate("/", beaconSettings: settings) // welcome screen
HSBeacon.navigate("/ask/message/", beaconSettings: settings) // message screen
HSBeacon.navigate("/docs/search?query=help", beaconSettings: settings) // equivalent to HSBeacon search
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
    <td>Boolean</td>
    <td>Enable or disable the contact options.</td>
  </tr>
  <tr>
    <td><pre>beaconTitle</pre></td>
    <td>String</td>
    <td>The navigation title shown on the intial Beacon screen (only if docs is enabled). Default is "Support".</td>
  </tr>
  <tr>
    <td><pre>useNavigationBarAppearance</pre></td>
    <td>Boolean</td>
    <td>If this is true, then Beacon will use tint colors defined via `UIAppearance` providing they are not nil; otherwise it will use the Beacon color.</td>
  </tr>
  <tr>
    <td><pre>useLocalTranslationOverrides</pre></td>
    <td>Boolean</td>
    <td>You may customize the user-facing strings in Beacon locally using `HSBeaconSettings`. This will tell Beacon to look for a `BeaconLocalizable.strings` file. You can find an example of this <a href="https://github.com/helpscout/beacon-ios-sdk/blob/master/Example/Beacon/BeaconLocalizable.strings">in the Beacon Example app</a>. If this flag isn't set, the translations provided in Beacon Builder will be used.
    </td>
  </tr>
</table>

## Useful Links

* [Changelog](https://github.com/helpscout/beacon-ios-sdk/blob/master/CHANGELOG.md) – get a list of recent changes to the Beacon SDK

[1]:	http://cocoapods.org
[2]:	https://github.com/Carthage/Carthage#adding-frameworks-to-an-application
