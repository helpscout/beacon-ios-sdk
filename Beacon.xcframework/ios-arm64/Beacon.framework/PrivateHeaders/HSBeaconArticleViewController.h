#import <UIKit/UIKit.h>
#import <Beacon/HSViewController.h>
#import <Beacon/HSBeaconContext.h>
#import <Beacon/HSBeaconSuggestion.h>
#import <Beacon/HSBeaconRelatedArticlesTableView.h>
#import <Beacon/HSCardStackViewController.h>

@interface HSBeaconArticleViewController : HSViewController <HSCardStackEmbeddable>

+ (instancetype)instantiate;

@property (nonatomic, strong) IBOutlet UIScrollView *containerScrollView;
@property (weak, nonatomic) IBOutlet HSBeaconRelatedArticlesTableView *relatedArticlesTableView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *relatedArticlesHeightConstraint;
@property (weak, nonatomic) IBOutlet UILabel *relatedArticlesLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *loadingIndicator;
@property (weak, nonatomic) IBOutlet UIView *scrollContentView;

- (void)updateWithArticleID:(NSString *)articleID context:(HSBeaconContext *)context;

@end
