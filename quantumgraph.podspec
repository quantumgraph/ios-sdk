Pod::Spec.new do |s|
  s.name         = "quantumgraph"
  s.version      = "2.3.0"
  s.summary      = "iOS Sdk helps you to analyse user events in your app"

  s.homepage     = "http://qgraph.io"
  s.documentation_url = "http://docs.qgraph.io"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "quantumgraph" => "vivek@quantumgraph.com" }
  s.platform     = :ios, '6.0'
  s.source       = { :git => "https://github.com/quantumgraph/ios-sdk.git", :tag => "v#{s.version}"}
  s.default_subspec = "ios-sdk"  
  
  s.subspec 'ios-sdk' do |ss|
    ss.source_files = "QGSdk.h"
    ss.vendored_library = "libQGSdk.a"
    ss.frameworks = 'AdSupport', 'CoreTelephony', 'SystemConfiguration', 'CoreLocation', 'ImageIO', 'MobileCoreServices' 
  end

  #s.source_files = "QGSdk.h"
  #s.vendored_library = "libQGSdk.a"
  s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"
end
