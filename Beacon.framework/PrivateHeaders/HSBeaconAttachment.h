#import <Foundation/Foundation.h>

@interface HSBeaconAttachment: NSObject

@property(readonly, nonatomic) NSString *filename;
@property(readonly, nonatomic) UIImage *image;
@property(readonly, nonatomic) CFStringRef uti;
@property(readonly, nonatomic) NSString *contentType;
@property(readonly, nonatomic) long size;

@property(nonatomic) NSData *data;
@property(nonatomic) NSString *attachmentId;
@property(nonatomic) float progress;
@property(nonatomic) BOOL uploadStarted;

- (nonnull instancetype)initWithData:(NSData *_Nonnull)data filename:(NSString *_Nonnull)filename image:(UIImage *_Nullable)image;

@end
