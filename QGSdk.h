//
//  QGSdk.h
//  QGSdk
//
//  Created by QuantumGraph
//  Copyright (c) 2015 QuantumGraph. All rights reserved.

#import <Foundation/Foundation.h>

@interface QGSdk : NSObject {
    NSString *_appId;
}

@property NSString *appId;
+ (QGSdk *) getSharedInstance;
- (void)setToken:(NSData *)tokenData;
- (void)onStop;
- (void)onStart:(NSString *)appId;
- (void)onStart:(NSString *)appId setDevProfile: (Boolean) devProfile;
- (void)setUserId:(NSString *)userId;
- (void)setName:(NSString *)name;
- (void)setFirstName:(NSString *)name;
- (void)setLastName:(NSString *)name;
- (void)setCity:(NSString *)city;
- (void)setEmail:(NSString *)email;
- (void)setDayOfBirth:(NSNumber *)day;
- (void)setMonthOfBirth:(NSNumber *)month;
- (void)setYearOfBirth:(NSNumber *)year;
- (void)setCustomKey:(NSString *)key withValue:(id)value;
- (void)logEvent:(NSString *)name;
- (void)logEvent:(NSString *)name withParameters:(NSDictionary *)parameters;
- (void)logEvent:(NSString *)name withValueToSum:(NSNumber *) valueToSum;
- (void)logEvent:(NSString *)name withParameters:(NSDictionary *)parameters withValueToSum:(NSNumber *) valueToSum;
- (void)setClickAttributionWindow:(NSInteger)seconds;
- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;
@end
