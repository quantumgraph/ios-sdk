//
//  QGSdk.h
//  QGSdk
//
//  Created by QuantumGraph
//  Copyright (c) 2015 QuantumGraph. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface QGSdk : NSObject

/*! 
 * Initialises QGSdk and returns the shared instance of the sdk
 * to access all the below methods
 */
+ (QGSdk *) getSharedInstance;

/*!
 * Set the Device Token received from APNS in the AppDelegate
 * implement this in application:didRegisterForRemoteNotificationsWithDeviceToken:
 * this method is required to identify device for sending push notification
 */
- (void)setToken:(NSData *)tokenData;

/*! This method is not used currently */
- (void)onStop;

/*!
 * @deprecated This method is deprecated starting in version 2.0.0
 * @note Please use @code onStart:setDevProfile: @endcode instead.
 * Avoid using this method, will be removed in later versions
 */
- (void)onStart:(NSString *)appId DEPRECATED_MSG_ATTRIBUTE(" since version 2.0.0, Use onStart:setDevProfile: instead");

/*!
 * This initialises the sdk with your app id
 * Add this method to you AppDelegate applicaiton:didFinishLaunchingWithOptions:
 * You can find it your account on app.qgraph.io in setup
 * for development profile pass your app id directly and set boolean true
 * for production profile set boolean false
 */
- (void)onStart:(NSString *)appId setDevProfile:(BOOL)devProfile;

/*!
 * set the unique user id for your users
 * you can identify your user with user_id while creating segment on app.qgraph.io
 */
- (void)setUserId:(NSString *)userId;

/*! set the name of the user */
- (void)setName:(NSString *)name;

/*! set the first name of the user */
- (void)setFirstName:(NSString *)name;

/*! set the last name of the user */
- (void)setLastName:(NSString *)name;

/*! set the city of the user */
- (void)setCity:(NSString *)city;

/*! set the email id of the user */
- (void)setEmail:(NSString *)email;

/*! set the day of DOB of the user */
- (void)setDayOfBirth:(NSNumber *)day;

/*! set the month of DOB of the user */
- (void)setMonthOfBirth:(NSNumber *)month;

/*! set the year of DOB of the user */
- (void)setYearOfBirth:(NSNumber *)year;

/*!
 * Use this method to set any custom key for the user
 * suppose you want to set rating of the user
 * setCustomKey:@"rating" withValue:3.5
 */
- (void)setCustomKey:(NSString *)key withValue:(id)value;

/*!
 * This methods help you track any particular event 
 * for example, viewing the products, playing a game or listening to a music
 *
 */
- (void)logEvent:(NSString *)name;

/*!
 * same as logEvent: 
 * You can pass custom parameter for the particular event
 * eg: for event: product_viewed, you want to track name of the product, brand, image url or any other details
 * pass all parameter for the event in a dictionary
 */
- (void)logEvent:(NSString *)name withParameters:(NSDictionary *)parameters;

/*!
 * Track monetary value associated with the event
 * eg: for event: product_viewed, price of the product is Rs 50
 * pass the value in the form of NSNumber
 */
- (void)logEvent:(NSString *)name withValueToSum:(NSNumber *) valueToSum;

/*!
 * This method is used to track event with parameters and value associated with it.
 * combination of logEvent:withParameter and logEvent:valueToSum
 */
- (void)logEvent:(NSString *)name withParameters:(NSDictionary *)parameters withValueToSum:(NSNumber *) valueToSum;

/*!
 * This method should be used to set the click through attribution window
 * Click through works for push notification (sent by QGraph) clicks and InApp Notification clicks
 * Set the time interval in seconds you want the click through attribution to work
 * Set 0 if you don't want to track click attribution
 * Default it is set to 24 hrs
 * eg: for click attribution window to be 12 hrs, pass the value: 43200
 */
- (void)setClickAttributionWindow:(NSInteger)seconds;

/*!
 * This method should be used to set the view through attribution window
 * View through attribution works only for InApp notifications
 * Similar to click through, set the window in seconds, set 0 to disable
 * Default it is set to 1 hr
 */
- (void)setAttributionWindow:(NSInteger)seconds;

/*!
 * This method allows to enable and disable InApp campaigns to be delivered to device
 * By default it is enabled, set 'YES' to disable it
 * Disabling it will prevent device to get any new InApp Campaigns
 * @note Use @code disableInAppCampaigns:YES @endcode to Disable
 */
- (void)disableInAppCampaigns:(BOOL)disabled;

/*!
 * Add this method to your AppDelegate applicaiton:didFinishLaunchingWithOptions:
 */
- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/*!
 * Add to your AppDelegate application:didReceiveRemoteNotification:fetchCompletionHandler:
 * pass all the push notifications received by the app
 * This method also let the sdk track app_launched event due to click on the notification sent by QGraph
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

@end
