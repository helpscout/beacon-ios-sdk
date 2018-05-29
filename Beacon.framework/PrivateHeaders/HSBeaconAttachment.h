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

-(instancetype)initWithData: (NSData *)data filename: (NSString *)filename image: (UIImage *)image;

@end
