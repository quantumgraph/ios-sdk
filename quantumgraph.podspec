Pod::Spec.new do |s|
  s.name         = "quantumgraph"
  s.version      = "4.4.2"
  s.summary      = "iOS Sdk helps you to track user events in your app and display notifications"

  s.homepage     = "https://www.appier.com/en/index.html"
  s.documentation_url = "https://docs.aiqua.appier.com/docs"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "appier" => "shiv.raj@appier.com" }
  s.platform     = :ios, '8.0'
  s.source       = { :git => "https://github.com/quantumgraph/ios-sdk.git", :tag => "v#{s.version}"}
  s.default_subspec = "ios-sdk"  
  
  s.subspec 'ios-sdk' do |ss|
    ss.library = 'z'
    ss.source_files = "QGSdk.h", "AIQP.h", "QGWKWebView.h"
    ss.vendored_library = "libQGSdk.a"
    ss.frameworks = 'AdSupport', 'CoreTelephony', 'SystemConfiguration', 'CoreLocation', 'ImageIO', 'MobileCoreServices' 
  end

  s.requires_arc = true

end
