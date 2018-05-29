#import <UIKit/UIKit.h>

#import "HSBeaconArticleCell.h"
#import "HSBeaconSuggestion.h"

@interface HSBeaconSuggestionCell: UITableViewCell <HSBeaconArticleCell>

@property(strong, nonatomic) HSBeaconSuggestion *suggestion;

@property(weak, nonatomic) IBOutlet UIImageView *image;
@property(weak, nonatomic) IBOutlet UILabel *nameLabel;



@end
