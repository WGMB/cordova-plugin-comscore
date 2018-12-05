#ifndef COMSCORE_IGNORE_CORDOVA_BRIDGE

//
//  SCORComScore.m
//  cordova-ios-lib
//
//  Copyright © 2015 comScore. All rights reserved.
//

#import "SCORComScore.h"
#import "SCORHelper.h"

@implementation SCORComScore

- (void)getScreenSize:(CDVInvokedUrlCommand *)command {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        CDVPluginResult *pluginResult = nil;
        
        NSArray *arr = [[SCORHelper deviceResolution] componentsSeparatedByString:@"x"];
        int width = [arr[0] intValue];
        int height = [arr[1] intValue];
        
        NSDictionary *dict = @{
                               @"height": @(height),
                               @"width": @(width),
                               @"innerWidth": @"",
                               @"innerHeight": @""
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}

- (void)networkInfo:(CDVInvokedUrlCommand *)command {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        CDVPluginResult *pluginResult = nil;
        
        NSString *connType = [SCORHelper connectionType];
        BOOL isConnected = [connType isEqualToString:@"none"]? NO:YES;
        
        NSDictionary *dict = @{
                               @"isConnected": @(isConnected),
                               @"connType": connType
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}

- (void)loadDeviceIds:(CDVInvokedUrlCommand *)command {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        SCORUniqueId * uniqueId = [SCORHelper uniqueId];
        SCORCrossPublisherIdSourceValue * crossPublisherIdData = [SCORHelper crossPublisherIdSourceValue];
        
        CDVPluginResult *pluginResult = nil;
        NSString *suffix = [NSString stringWithFormat:@"%ld%ld", (long)[uniqueId commonness], (long)[uniqueId persistency]];
        NSDictionary *dict = @{
                               @"visitorID" : [uniqueId uniqueId],
                               @"suffix" : suffix,
                               @"crossPublisherID" : ([crossPublisherIdData sourceValue])?: @"",
                               @"alwaysSend": ([crossPublisherIdData alwaysSend])? @"true" : @"false"
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}

- (void)isJailBroken:(CDVInvokedUrlCommand *)command {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        CDVPluginResult *pluginResult = nil;
        
        BOOL isRoot = [SCORHelper deviceIsJailBroken];
        NSDictionary *dict = @{@"isRoot" : @(isRoot)};
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}

- (void) getSystemInfo:(CDVInvokedUrlCommand *)command
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        CDVPluginResult *pluginResult = nil;
        
        NSString *packageName = [SCORHelper packageName];
        NSString *lang = [SCORHelper deviceLanguage];
        NSString *archName = [SCORHelper deviceArchitecture];
        NSString *model = [SCORHelper deviceName];
        NSString *systemVersion = [SCORHelper platformVersion];
        NSString *platformName = [SCORHelper platformName];
        
        NSDictionary *dict = @{
                               @"packageName" : packageName,
                               @"lang" : lang,
                               @"arch": archName,
                               @"model": model,
                               @"systemVersion": systemVersion,
                               @"os": platformName
                               };
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    });
}


@end
#endif
