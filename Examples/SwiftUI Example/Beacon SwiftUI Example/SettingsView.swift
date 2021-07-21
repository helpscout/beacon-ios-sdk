import Foundation
import SwiftUI
import Beacon

struct SettingsView: View {

    var body: some View {
        return Button("Contact Us") {
            #warning("You must provide a valid Beacon ID")
            let settings = HSBeaconSettings(beaconId: "")
            HSBeacon.open(settings)
        }
    }

}
