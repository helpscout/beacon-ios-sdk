#import <UIKit/UIKit.h>

@class HSBeaconArticleDetails;

@protocol HSBeaconRelatedArticlesTableProtocol
- (void)relatedArticlesTableViewDidSelectArticleDetails:(HSBeaconArticleDetails *)articleDetails;
@end

@interface HSBeaconRelatedArticlesTableView : UITableView

@property (nonatomic, weak) id<HSBeaconRelatedArticlesTableProtocol> relatedArticlesDelegate;

@property (nonatomic) HSBeaconArticleDetails *articleDetails;

@end
