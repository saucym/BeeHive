/**
 * Created by BeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
#import <UserNotifications/UserNotifications.h>
#endif


@interface BHAppDelegate : UIResponder <UIApplicationDelegate>

@end

typedef void (^BHNotificationResultHandler)(UIBackgroundFetchResult);
typedef void (^BHNotificationPresentationOptionsHandler)(UNNotificationPresentationOptions options) API_AVAILABLE(ios(10.0));
typedef void (^BHNotificationCompletionHandler)(void);

@interface BHNotificationsItem : NSObject

@property (nonatomic, strong) NSError *notificationsError;
@property (nonatomic, strong) NSData *deviceToken;
@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, copy) BHNotificationResultHandler notificationResultHander;
@property (nonatomic, strong) UILocalNotification *localNotification;
@property (nonatomic, strong) UNNotification *notification API_AVAILABLE(ios(10.0));
@property (nonatomic, strong) UNNotificationResponse *notificationResponse API_AVAILABLE(ios(10.0));
@property (nonatomic, copy) BHNotificationPresentationOptionsHandler notificationPresentationOptionsHandler API_AVAILABLE(ios(10.0));
@property (nonatomic, copy) BHNotificationCompletionHandler notificationCompletionHandler;
@property (nonatomic, strong) UNUserNotificationCenter *center API_AVAILABLE(ios(10.0));

@end

@interface BHOpenURLItem : NSObject

@property (nonatomic, strong) NSURL *openURL;
@property (nonatomic, copy) NSString *sourceApplication;
@property (nonatomic, strong) id annotation;
@property (nonatomic, strong) NSDictionary *options;

@end

typedef void (^BHShortcutCompletionHandler)(BOOL);

@interface BHShortcutItem : NSObject

@property(nonatomic, strong) UIApplicationShortcutItem *shortcutItem API_AVAILABLE(ios(9.0));
@property(nonatomic, copy) BHShortcutCompletionHandler scompletionHandler;

@end


typedef void (^BHUserActivityRestorationHandler)(NSArray *);

@interface BHUserActivityItem : NSObject

@property (nonatomic, copy) NSString *userActivityType;
@property (nonatomic, strong) NSUserActivity *userActivity;
@property (nonatomic, strong) NSError *userActivityError;
@property (nonatomic, copy) BHUserActivityRestorationHandler restorationHandler;

@end

typedef void (^BHWatchReplyHandler)(NSDictionary *replyInfo);

@interface BHWatchItem : NSObject

@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, copy) BHWatchReplyHandler replyHandler;

@end


