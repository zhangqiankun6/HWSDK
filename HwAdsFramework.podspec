
Pod::Spec.new do |spec|

  spec.name         = "HwAdsFramework"
  spec.version      = "1.0.2"
  spec.summary      = "A short description of HwAdsFramework."

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  spec.description  = "A short description of HwAdsFramework."

  spec.homepage     = "https://github.com/zhangqiankun6/TestRelease"
  # spec.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Licensing your code is important. See https://choosealicense.com for more info.
  #  CocoaPods will detect a license file if there is a named LICENSE*
  #  Popular ones are 'MIT', 'BSD' and 'Apache License, Version 2.0'.
  #

  # spec.license      = "MIT (example)"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }


  spec.author             = { "乾坤" => "1428815778@qq.com" }
  # Or just: spec.author    = "乾坤"
  # spec.authors            = { "乾坤" => "1428815778@qq.com" }
  # spec.social_media_url   = "https://twitter.com/乾坤"

  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If this Pod runs only on iOS or OS X, then specify the platform and
  #  the deployment target. You can optionally include the target after the platform.
  #

  # spec.platform     = :ios
   spec.platform     = :ios, "10.0"

  #  When using multiple platforms
  # spec.ios.deployment_target = "5.0"
  # spec.osx.deployment_target = "10.7"
  # spec.watchos.deployment_target = "2.0"
  # spec.tvos.deployment_target = "9.0"


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  #

  spec.source       = { :git => "https://github.com/zhangqiankun6/TestRelease.git", :tag => "#{spec.version}" }

  spec.vendored_frameworks = "Frameworks/HwAdsFramework.framework"

  spec.source_files  = "Frameworks/**/*.{h,m}"
  spec.exclude_files = "Classes/Exclude"
  spec.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => '' }

  # spec.public_header_files = "Classes/**/*.h"


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # spec.framework  = "SomeFramework"
  # spec.frameworks = "SomeFramework", "AnotherFramework"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

  # spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  spec.dependency "AppLovinSDK"
  spec.dependency "Adjust"
  spec.dependency "AppLovinMediationAdColonyAdapter"
  spec.dependency "AppLovinMediationChartboostAdapter"
  spec.dependency "AppLovinMediationFyberAdapter"

  spec.dependency "AppLovinMediationGoogleAdManagerAdapter"
  spec.dependency "AppLovinMediationGoogleAdapter"
  spec.dependency "AppLovinMediationInMobiAdapter"
  spec.dependency "AppLovinMediationIronSourceAdapter"
  spec.dependency "AppLovinMediationFacebookAdapter"
  spec.dependency "AppLovinMediationMintegralAdapter"
  spec.dependency "AppLovinMediationByteDanceAdapter"

  spec.dependency "AppLovinMediationSmaatoAdapter"
  spec.dependency "AppLovinMediationTapjoyAdapter"
  spec.dependency "AppLovinMediationTencentGDTAdapter"
  spec.dependency "AppLovinMediationUnityAdsAdapter"
  spec.dependency "AppLovinMediationVungleAdapter"

end
