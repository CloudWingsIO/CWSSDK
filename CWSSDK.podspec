Pod::Spec.new do |s|
s.name             = "CWSSDK"
s.version          = "2.1.0"
s.summary          = "Cloud Wings iOS Shake SDK."
s.homepage         = "https://github.com/ShakeAI/CWSSDK"
s.license          = {
    					:type => "Copyright",
    					:text => "Cloud Wings."
                      }
s.authors          = { "cloudwings" => "team@cloudwings.io" }
s.source           = { :git => 'https://github.com/ShakeAI/CWSSDK.git', :tag => s.version, :submodules => true }

s.platform     = :ios, '9.0'
s.requires_arc = true

s.vendored_frameworks = 'frameworks/cocoapods/CWSShakeSDK.framework'

s.frameworks = 'Foundation', 'UIKit'

end
