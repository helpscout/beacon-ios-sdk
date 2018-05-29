#import <UIKit/UIKit.h>

#import "HSBeaconArticleCell.h"
#import "HSBeaconArticleSearchResult.h"

@interface HSBeaconSearchResultsCell: UITableViewCell <HSBeaconArticleCell>

@property(strong, nonatomic) HSBeaconArticleSearchResult *searchResult;

@property (weak, nonatomic) IBOutlet UIView *resultContainer;
@property(weak, nonatomic) IBOutlet UILabel *nameLabel;
@property(weak, nonatomic) IBOutlet UILabel *previewLabel;

-(void)setPreviewText:(NSString *)previewText;

@end
