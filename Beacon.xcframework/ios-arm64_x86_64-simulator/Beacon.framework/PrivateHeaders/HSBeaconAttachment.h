#import <UIKit/UIKit.h>
#import <Beacon/HSBeaconContactForm.h>

NS_ASSUME_NONNULL_BEGIN

@interface HSBeaconAttachment: NSObject <HSBeaconContactFormAttachment>

@property(readonly, nonatomic) NSString *filename;
@property(readonly, nonatomic) NSString *contentType;

@property(nonatomic, strong, nullable) NSData *data;

- (nonnull instancetype)initWithData:(NSData *_Nonnull)data filename:(NSString *_Nonnull)filename;

@end

NS_ASSUME_NONNULL_END
