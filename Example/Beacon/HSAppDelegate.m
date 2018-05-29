#import "HSAppDelegate.h"

@implementation HSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UINavigationBar.appearance.barTintColor = [UIColor colorWithRed:0.00f green:0.55f blue:0.95f alpha:1.0f];
    UIApplication.sharedApplication.statusBarStyle = UIStatusBarStyleLightContent;
    
    return YES;
}

@end
