#import <Beacon/Beacon.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconContactForm (Private)

/**
 Create a contact form with the specified Beacon id. As a developer you won't need to
 create a contact form, as the SDK will initialize the object and pass it to the delegate
 method.
 */
- (instancetype)initWithBeaconID:(NSString *)beaconID;

/**
 Internal factory method for creating contact forms from Swift code.
 This exists because the initializer is marked unavailable in the public header,
 preventing direct Swift access even with @_implementationOnly imports.

 @param beaconID The Beacon ID for this form
 @return A new HSBeaconContactForm instance
 */
+ (instancetype)createWithBeaconID:(NSString *)beaconID;

@end

NS_ASSUME_NONNULL_END
