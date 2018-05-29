#import "HSViewController.h"

@import Beacon;

@interface HSViewController ()

@end

@implementation HSViewController

static NSString *const DEFAULT_BEACON_ID = @"43f48699-c851-4526-943c-87c3fc1fbe69";
static NSString *const DEFAULTS_KEY = @"HSBeaconExampleSavedFormValues";
static NSString *const BEACON_ID_KEY = @"beaconId";
static NSString *const EMAIL_KEY = @"email";
static NSString *const NAME_KEY = @"name";
static NSString *const SIGNATURE_KEY = @"signature";


- (void)viewDidLoad {
    [super viewDidLoad];
    NSDictionary<NSString *, NSString *> *savedFormValues = [[NSUserDefaults standardUserDefaults] dictionaryForKey:DEFAULTS_KEY];

    NSString *savedBeaconId = savedFormValues[BEACON_ID_KEY];
    self.beaconIdText.text = savedBeaconId.length > 0 ? savedBeaconId : DEFAULT_BEACON_ID;
    self.emailTextField.text = savedFormValues[EMAIL_KEY];
    self.nameTextField.text = savedFormValues[NAME_KEY];
    self.signatureText.text = savedFormValues[SIGNATURE_KEY];

    self.title = @"Beacon Example";
    self.navigationController.navigationBar.titleTextAttributes = @{ NSForegroundColorAttributeName: UIColor.whiteColor };
    self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
}

- (IBAction)openBeacon:(id)sender {
    if ([self.emailTextField.text length] > 0) {
        HSBeaconUser *user = [[HSBeaconUser alloc] init];
        user.email = self.emailTextField.text;
        user.name = self.nameTextField.text;
        
        [HSBeacon login:user];
    }

    HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:_beaconIdText.text];
    settings.useNavigationBarAppearance = NO;
    settings.beaconTitle = @"Example Support";

    NSString *signature = (self.signatureText.text.length > 0) ? self.signatureText.text : nil;
    [HSBeacon openBeacon:settings signature:signature];

    NSDictionary<NSString *, NSString *> *formValues = @{
        BEACON_ID_KEY : self.beaconIdText.text,
        EMAIL_KEY: self.emailTextField.text,
        NAME_KEY: self.nameTextField.text,
        SIGNATURE_KEY: self.signatureText.text
    };
    [[NSUserDefaults standardUserDefaults] setObject:formValues forKey:DEFAULTS_KEY];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

@end