#import <Foundation/Foundation.h>

/**
 `HSBeaconUser` represents a user identified with Help Scout, allowing you to
 match up support requests to your customer base.

 The current user may be identified by creating an `HSBeaconUser` object,
 configuring its properties, and then identifying them using `[HSBeacon identify:]`.
 */
@interface HSBeaconUser: NSObject

/**
 The email address for the current user.
 */
@property(strong, nonatomic) NSString *email;

/**
 The name of the current user.
 */
@property(strong, nonatomic) NSString *name;

/**
 The attributes for the current user. These are arbitrary key/value pairs that
 will be sent to Help Scout to help identify the current user. You may add up to
 10 different attributes.
 */
@property(strong, nonatomic, readonly) NSDictionary *attributes;

/**
 Adds an attribute with a given key to the attributes dictionary. The attributes
 dictionary is limited to 10 entries.

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

@end
