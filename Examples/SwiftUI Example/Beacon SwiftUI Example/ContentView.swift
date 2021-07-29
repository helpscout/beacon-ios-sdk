import SwiftUI
import Beacon

struct ContentView: View {
    @State private var showingSettings = false

    var body: some View {
        Button("Open Settings") {
            showingSettings.toggle()
        }.sheet(isPresented: $showingSettings) {
            SettingsView()
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    
    static var previews: some View {
        ContentView()
    }
}
