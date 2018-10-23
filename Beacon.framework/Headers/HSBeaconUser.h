#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `HSBeaconUser` represents a user identified with Help Scout, allowing you to
 match up support requests to your customer base.

 The current user may be identified by creating an `HSBeaconUser` object,
 configuring its properties, and then identifying them using `[HSBeacon identify:]`.
 */
@interface HSBeaconUser: NSObject

extern const NSUInteger HSBeaconMaximumUserAttributes;

/**
 The email address for the current user.
 */
@property(strong, nonatomic, nullable) NSString *email;

/**
 The name of the current user.
 */
@property(strong, nonatomic, nullable) NSString *name;

/**
 The attributes for the current user. These are arbitrary key/value pairs that
 will be sent to Help Scout to help identify the current user. You may add up to
 30 different attributes.
 */
@property(strong, nonatomic, readonly) NSDictionary *attributes;

/**
 Adds an attribute with a given key to the attributes dictionary. The attributes
 dictionary is limited to 30 entries.

 @returns True if the attribute was added; false if the attribute limit has been reached.
 */
- (BOOL)addAttributeWithKey:(NSString *)key value:(NSString *)value;

/**
 Removes an attribute with a given key from the attributes dictionary.
 */
- (void)removeAttributeWithKey:(NSString *)key;

/**
 Clears the current attributes dictionary.
 */
- (void)clearAttributes;

/**
 Check if two users are equal
 */
- (BOOL)isEqualToBeaconUser:(HSBeaconUser *)user;

@end

NS_ASSUME_NONNULL_END
