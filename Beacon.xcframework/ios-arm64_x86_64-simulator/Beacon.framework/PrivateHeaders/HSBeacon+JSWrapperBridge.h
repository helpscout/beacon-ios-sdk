//
//  HSBeacon+JSWrapperBridge.h
//  Beacon
//
//  Internal bridge for JS Wrapper integration
//  This header is NOT included in public framework headers
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Beacon/HSBeacon.h>

@class HSBeaconSettings;

/// Internal category for JS Wrapper bridge
/// These methods are only available within the framework and not exposed to external users
/// This category bridges Objective-C calls to internal Swift methods
@interface HSBeacon (JSWrapperBridge)

/// Check if JS wrapper should be used
+ (BOOL)shouldUseJSWrapper;

/// Enable/disable JS wrapper
+ (void)setUseJSWrapper:(BOOL)enabled;

/// Open beacon with JS wrapper
+ (void)openBeaconWithJSWrapperFromSettings:(nonnull HSBeaconSettings *)settings 
                                       from:(nullable UIViewController *)viewController 
                                  signature:(nullable NSString *)signature;

/// Dismiss JS wrapper
+ (void)dismissWithJSWrapper:(void (^ _Nullable)(void))completion;

/// Identify user with JS wrapper
+ (void)identifyWithJSWrapper:(nonnull HSBeaconUser *)user;

/// Logout user with JS wrapper
+ (void)logoutWithJSWrapper;

/// Logout user with JS wrapper with optional endActiveChat behavior
+ (void)logoutWithJSWrapperWithEndActiveChat:(BOOL)endActiveChat;

/// Get current user with JS wrapper
+ (nullable HSBeaconUser *)currentUserWithJSWrapper;

/// Open article with JS wrapper
+ (void)openArticleWithJSWrapper:(nonnull NSString *)articleId
                        settings:(nonnull HSBeaconSettings *)settings
                            from:(nullable UIViewController *)viewController
                       signature:(nullable NSString *)signature;

/// Search with JS wrapper
+ (void)searchWithJSWrapper:(nonnull NSString *)query
                   settings:(nonnull HSBeaconSettings *)settings
                       from:(nullable UIViewController *)viewController
                  signature:(nullable NSString *)signature;

/// Navigate with JS wrapper
+ (void)navigateWithJSWrapper:(nonnull NSString *)route
                     settings:(nonnull HSBeaconSettings *)settings
                         from:(nullable UIViewController *)viewController
                    signature:(nullable NSString *)signature;

/// Ask a question in AI Answers with JS wrapper
+ (void)askQuestionWithJSWrapper:(nonnull NSString *)question
                        settings:(nonnull HSBeaconSettings *)settings
                            from:(nullable UIViewController *)viewController
                       signature:(nullable NSString *)signature;

/// Suggest article IDs with JS wrapper
+ (void)suggestWithJSWrapper:(nonnull NSArray<NSString *> *)articleIds;

/// Suggest mixed items (articles and links) with JS wrapper
+ (void)suggestWithItemsJSWrapper:(nonnull NSArray<id<HSBeaconSuggestionItem>> *)suggestions;

/// Reset the contact form with JS wrapper
+ (void)resetWithJSWrapper;

@end 
