# Beacon

- [Installation](#installation)
- [Usage](#usage)
- [Running The Example App](#running-the-example-app)
- [License](#license)

## Installation

#### CocoaPods

Beacon is available through [CocoaPods](http://cocoapods.org). To install it, simply add the following line to your `Podfile`:

```ruby
pod 'Beacon'
```

#### Carthage

Beacon can be installed using Carthage by adding the following line to your `Cartfile` and then following the [Carthage installation instructions](https://github.com/Carthage/Carthage#adding-frameworks-to-an-application):

```ruby
github "helpscout/beacon-ios-sdk"
```

## Usage

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

#### Authenticating Users

Authenticating with Beacon is optional, but if you have information you'd like
to associate with users, you can do so using `HSBeaconUser` and the `login:`
method before showing the Beacon:

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

#### Secure Mode

Secure mode authentication uses an user identifier (similar to basic mode) but also requires a signature. The signature must be computed on a *per user* basis using the secret key. The Secret Key is provided on the Manage Beacon page > Messaging > Advance Options.

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

### User Attributes

`HSBeaconUser` supports the addition of up to 10 attributes. These are arbitrary key-value pairs to allow you to add extra identifying information to a user.

You may add an attribute like so:

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

## Running The Example App

To run the example project, clone the Beacon repo and run `pod install` from the Example directory. Once installation is complete, open `Beacon Example.xcworkspace` and run the `Beacon Example` scheme.

