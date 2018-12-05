//
// Copyright (c) 2017 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kSCORWrongMacAddresses [NSSet setWithObjects:@"", @"02:00:00:00:00:00", @"00:00:00:00:00:00", @"FF:FF:FF:FF:FF:FF", @"ff:ff:ff:ff:ff:ff", nil]

typedef NS_ENUM(NSInteger, SCORUniqueIdSource) {
    SCORUniqueIdSourceGenerated = 0,
    SCORUniqueIdSourceVendorId = 1,
    SCORUniqueIdSourceMAC = 2
};

typedef NS_ENUM(NSInteger, SCORCrossPublisherIdSource) {
    SCORCrossPublisherIdSourceNotPresent = 0,
    SCORCrossPublisherIdSourceADID = 1,
    SCORCrossPublisherIdSourceMAC = 2
};

/**
 *  Encapsulates a Unique Id and it's metadata.
 */
@interface SCORUniqueId : NSObject
/**
 *  Generated Unique Id.
 */
@property (readonly, nonatomic) NSString    * uniqueId;
/**
 *  The commonness level, from 1 - 7, a 0 means that the commoness in unknown.
 */
@property (readonly) NSInteger              commonness;
/**
 *  The persistency level, from 1 - 5, a 0 means that the persistency will depend on the caller.
 */
@property (readonly) NSInteger              persistency;
/**
 The source of the uniqueId
 */
@property (readonly) SCORUniqueIdSource     source;

@end

/**
 *  Encapsulates a CrossPublisher Id and it's metadata.
 */
@interface SCORCrossPublisherIdSourceValue : NSObject
/**
 *  Generated CrossPublisher Id Source Value.
 */
@property (readonly, nonatomic) NSString            * sourceValue;
/**
 *  Decides that we always send the ciphered CPI and avoid using the ns_ap_ni label. It is useful for certain branches of the decision tree.
 */
@property (readonly) BOOL                           alwaysSend;
/**
 The source of the uniqueId
 */
@property (readonly) SCORCrossPublisherIdSource     source;

@end

/**
 *  Provides common utilities to retrieve information required by the Tag libraries (application name, version, OS information, language, etc.).
 */

@interface SCORHelper : NSObject

/**
 *  The App Name, based on the App bundle.
 *
 *  @return A NSString with the App name, or "none" if it wasn't possible to obtain a name.
 */
+ (NSString *)appName;

/**
 *  The App version, based on the App bundle.
 *
 *  @return A NSString
 */
+ (NSString *)appVersion;

/**
 *  Current device model.
 *
 *  @return NSString
 */
+ (NSString *)deviceName;

/**
 *  Current device system version.
 *
 *  @return NSString
 */
+ (NSString *)platformVersion;

/**
 *  Current device platform.
 *
 *  @return Either "iOS" or "tvOS".
 */
+ (NSString *)platformName;

/**
 *  Current device screen resolution.
 *
 *  @return A string of the format "[with]x[height]"
 */
+ (NSString *)deviceResolution;

/**
 *  Returns the current App Window resolution, this method may return "0x0" if it wasn't possible to obtain a valid resolution.
 *
 *  @return A string of the format "[with]x[height]"
 */
+ (NSString *)appWindowResolution;

/**
 *  Current device preferred language.
 *
 *  @return A string with the language, or "unknown".
 */
+ (NSString *)deviceLanguage;

/**
 *  Current App bundle id.
 *
 *  @return NSString
 */
+ (NSString *)packageName;

/**
 *  Current device architecture.
 *
 *  @return The device architecture, or "na" if it wasn't possible to obtain.
 */
+ (NSString *)deviceArchitecture;

/**
 *  The current connection type. This method will return "none" when it doesn't have reachability, even if is connected to a network.
 *
 *  @return Either "wwan", "wifi" or "none".
 */
+ (NSString *)connectionType;

/**
 *  Returns YES if the device is Jail Broken, NO otherwise.
 *
 *  @return Either YES or NO.
 */
+ (BOOL)deviceIsJailBroken;

/**
 *   Returns a NSString with the MAC address of the current device if is valid (It's not an empty or place holder MAC
 *   address), returns *nil* otherwise.
 *
 *   @return NSString or *nil*
 */
+ (NSString *)plainMACAddress;

/**
 *   Returns YES if the current device MAC address is valid (Is not empty or a placeholder).
 *
 *   @return BOOL
 */
+ (BOOL)isMACAddressValid;

/**
 *  Will return a <SCORUniqueId> with the current device id and metadata. Please refer to <SCORUniqueId> documentation to understand the returned values.
 *
 *  @return SCORUniqueId
 */
+ (SCORUniqueId *)uniqueId;

/**
 *  Will return a NSString with the generated cross publisher id, if any. If *Limit Ad Tracking* is enabled will return "none", if AdSupport is not available and there's no valid mac address will return *nil*.
 *
 *  @return NSString or *nil*
 */
+ (SCORCrossPublisherIdSourceValue *)crossPublisherIdSourceValue;

/**
 *  Returns YES if AdFramework is available in the current environment.
 *
 *  @return BOOL
 */
+ (BOOL)isAdFrameworkAvailable;

/**
 *  Retuns YES if "Limit Ad Tracking" is currently enabled.
 *
 *  @return BOOL
 */
+ (BOOL)isLimitAdTrackingEnabled;

/**
 *  Returns the raw advertising id value
 *
 *  @return NSString or *nil*
 */
+ (NSString *)trackingID;

@end
