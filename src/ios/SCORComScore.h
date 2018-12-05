//
//  SCORComScore.h
//  comScore
//
// Copyright 2015 comScore, Inc. All right reserved.
//

#ifndef COMSCORE_IGNORE_CORDOVA_BRIDGE

#import <Cordova/CDVPlugin.h>

@interface SCORComScore : CDVPlugin

- (void) getScreenSize:(CDVInvokedUrlCommand*)command;
- (void) networkInfo:(CDVInvokedUrlCommand*)command;
- (void) loadDeviceIds:(CDVInvokedUrlCommand*)command;
- (void) isJailBroken:(CDVInvokedUrlCommand *)command;
- (void) getSystemInfo:(CDVInvokedUrlCommand *)command;

@end
#endif
