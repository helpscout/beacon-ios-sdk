@import Foundation;

/// HSBeaconFocusMode represents various configuration modes of Beacon.
/// Allowing you to customize the experience your users have, from getting in contact
/// right away, to a more self service approach.  More info is available AT https://docs.helpscout.com/article/1296-work-with-beacon-modes
typedef NS_ENUM(NSUInteger, HSBeaconFocusMode) {
    /// An option to see both help articles and contact options side by side
    HSBeaconFocusModeNeutral,
    /// An option to see help articles first and contact options after interacting with content
    HSBeaconFocusModeSelfService,
    /// An option to see contact options first and help articles second
    HSBeaconFocusModeAskFirst
};
