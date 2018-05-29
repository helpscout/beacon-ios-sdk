#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#import "HSBeaconContext.h"
#import "HSBeaconSuggestion.h"
#import "HSBeaconRelatedArticlesTableView.h"
#import "HSCardStackViewController.h"

@interface HSBeaconArticleViewController : UIViewController <HSCardStackEmbeddable>

@property (nonatomic, strong) IBOutlet UIScrollView *containerScrollView;
@property (weak, nonatomic) IBOutlet UIWebView *webView;
@property (weak, nonatomic) IBOutlet HSBeaconRelatedArticlesTableView *relatedArticlesTableView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *webViewHeightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *relatedArticlesHeightConstraint;
@property (weak, nonatomic) IBOutlet UILabel *relatedArticlesLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *loadingIndicator;

- (void)updateWithArticleID:(NSString *)articleID context:(HSBeaconContext *)context;

@end
