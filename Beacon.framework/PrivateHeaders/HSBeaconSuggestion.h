#import <Foundation/Foundation.h>

#import "HSBeaconArticle.h"

@interface HSBeaconSuggestion: HSBeaconArticle

@property (readonly, nonatomic) NSURL *URL;
@property (readonly, nonatomic) NSString *type;

-(instancetype)initWithDictionary: (NSDictionary *)dictionary;

-(BOOL)isArticle;

-(BOOL)isLink;

@end
