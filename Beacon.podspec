Pod::Spec.new do |s|
  s.name          = 'Beacon'
  s.swift_version = '5.0'
  s.version       = '2.2.0'
  s.summary       = 'The Help Scout Beacon SDK'
  s.license       = { :type => 'Commercial', :text => 'Help Scout. All rights reserved.' }

  s.description   = <<-DESC
                   The Help Scout Beacon SDK. Learn more at https://developer.helpscout.com/beacon-2/.
                   DESC

  s.homepage      = 'http://github.com/helpscout/beacon-ios-sdk'
  s.author        = { 'Help Scout' => 'help@helpscout.com' }
  s.platform      = :ios, '11.0'
  s.source        = { :git => 'https://github.com/helpscout/beacon-ios-sdk.git', :tag => s.version }

  s.source_files  = 'Beacon.xcframework/ios-arm64/Beacon.framework/Headers/*.h'
  s.module_map    = 'Beacon.xcframework/ios-arm64/Beacon.framework/Modules/module.modulemap'  
  s.preserve_paths = 'Beacon.xcframework'
  s.vendored_frameworks = 'Beacon.xcframework'
  s.frameworks    = 'UIKit', 'Photos', 'UserNotifications', 'WebKit', 'MobileCoreServices', 'SafariServices', 'QuickLook', 'CoreData'
end
