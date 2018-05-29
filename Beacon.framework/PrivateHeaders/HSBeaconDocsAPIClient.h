#import <Foundation/Foundation.h>
#import "HSBeaconConfig.h"
#import "HSBeaconArticleDetails.h"
#import "HSBeaconPaginatedResponse.h"
#import "HSBeaconArticleSearchResult.h"
#import "HSBeaconPaging.h"
#import "HSBeaconBaseAPIClient.h"
#import "HSBeaconSuggestion.h"

@interface HSBeaconDocsAPIClient : HSBeaconBaseAPIClient

- (NSURLSessionDataTask *)fetchArticle:(NSString *)articleId completionHandler: (void (^)(HSBeaconArticleDetails *article, NSError *error))completion;

- (NSURLSessionDataTask *)fetchSearchResults:query page:(int)page completionHandler:(void (^)(HSBeaconPaginatedResponse *results, NSError *error)) completion;

@end
