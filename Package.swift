// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Beacon-iOS",
    defaultLocalization: "en",
    platforms: [
        .iOS(.v11)
    ],
    products: [
        .library(
            name: "Beacon-iOS",
            targets: ["Beacon"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "Beacon",
            path: "Beacon.xcframework")
    ]
)
