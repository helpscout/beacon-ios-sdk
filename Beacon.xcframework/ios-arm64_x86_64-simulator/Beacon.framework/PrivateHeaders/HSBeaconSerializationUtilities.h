#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconSerializationUtilities : NSObject

+ (void)saveConversationID:(NSString *)conversationID mappedToBeaconID:(NSString *)beaconID;
+ (void)saveChatID:(NSUUID *)chatId mappedToBeaconID:(NSString *)beaconID;

+ (nullable NSString *)beaconIDForConversationID:(nullable NSNumber *)conversationID;
+ (nullable NSString *)beaconIDForChatID:(nullable NSString *)chatID;

+ (BOOL)isBeaconInitialized;

+ (void)setBeaconInitialized;
+ (void)clearBeaconInitialized;

+ (nullable NSString *)localBeaconDeviceId;
+ (void)setLocalBeaconDeviceId:(NSString *)deviceId;
+ (void)clearLocalBeaconDeviceId;
+ (BOOL)hasLocalBeaconInstallMarker;
+ (void)setLocalBeaconInstallMarker;
+ (void)clearLocalBeaconInstallMarker;

+ (nullable NSString *)localBeaconPushToken;
+ (void)setLocalBeaconPushToken:(NSString *)pushToken;
+ (void)clearLocalBeaconPushToken;

+ (BOOL)isLocalBeaconTokenRegistered;
+ (void)setLocalBeaconTokenRegistered:(BOOL)registered;

+ (nullable NSString *)localBeaconLastRegisteredBeaconId;
+ (nullable NSString *)localBeaconLastRegisteredDeviceId;
+ (void)setLocalBeaconLastRegisteredContextWithBeaconId:(NSString *)beaconId deviceId:(NSString *)deviceId;
+ (void)clearLocalBeaconLastRegisteredContext;
+ (BOOL)invalidateLocalBeaconTokenRegistrationIfContextChangedWithBeaconId:(nullable NSString *)beaconId
                                                                  deviceId:(nullable NSString *)deviceId;

@end

NS_ASSUME_NONNULL_END
