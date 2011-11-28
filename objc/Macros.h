//
//  Macros.h
//
//  Created by John Iacoviello on 11/26/11.
//

// Constants
#define APP_VERSION                             [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]
#define APP_NAME                                [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleName"]
#define APP_DELEGATE                            [[UIApplication sharedApplication] delegate]
#define USER_DEFAULTS                           [NSUserDefaults standardUserDefaults]
#define APPLICATION                             [UIApplication sharedApplication]
#define BUNDLE                                  [NSBundle mainBundle]
#define MAIN_SCREEN                             [UIScreen mainScreen]
#define NAV_BAR                                 self.navigationController.navigationBar
#define TAB_BAR                                 self.tabBarController.tabBar
#define DATE_COMPONENTS                         NSYearCalendarUnit|NSMonthCalendarUnit|NSDayCalendarUnit
#define IS_PAD                                  ([[UIDevice currentDevice] interfaceIdiom] == UIUserInterfaceIdiomPad)

// Props
#define ScreenWidth                             [MAIN_SCREEN bounds].size.width
#define ScreenHeight                            [MAIN_SCREEN bounds].size.height
#define NavBarHeight                            self.navigationController.navigationBar.bounds.size.height
#define TabBarHeight                            self.tabBarController.tabBar.bounds.size.height
#define SelfBoundsWidth                         self.bounds.size.width
#define SelfBoundsHeight                        self.bounds.size.height
#define SelfFrameWidth                          self.frame.size.width
#define SelfFrameHeight                         self.frame.size.height
#define SelfViewBoundsWidth                     self.view.bounds.size.width
#define SelfViewBoundsHeight                    self.view.bounds.size.height
#define SelfViewFrameWidth                      self.view.frame.size.width
#define SelfViewFrameHeight                     self.view.frame.size.height
#define SelfX                                   self.frame.origin.x
#define SelfY                                   self.frame.origin.y
#define SelfViewX                               self.view.frame.origin.x
#define SelfViewY                               self.view.frame.origin.y

// Utils
#define clamp(n,min,max)                        ((n < min) ? min : (n > max) ? max : n)
#define hex_rgba(c)                             [UIColor colorWithRed:((c>>24)&0xFF)/255.0 green:((c>>16)&0xFF)/255.0 blue:((c>>8)&0xFF)/255.0 alpha:((c)&0xFF)/255.0]
#define hex_rgb(c)                              [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:((c)&0xFF)/255.0 alpha:1.0]
#define frameWidth(v)                           v.frame.size.width
#define frameHeight(v)                          v.frame.size.height
#define boundsWidth(v)                          v.bounds.size.width
#define boundsHeight(v)                         v.bounds.size.height
#define posX(v)                                 v.frame.origin.x
#define posY(v)                                 v.frame.origin.y
#define setPosX(v,x)                            v.frame = CGRectMake(x, posY(v), frameWidth(v), frameHeight(v))
#define setPosY(v,y)                            v.frame = CGRectMake(posX(v), y, frameWidth(v), frameHeight(v))
#define setFramePosition(v,x,y)                 v.frame = CGRectMake(x, y, frameWidth(v), frameHeight(v))
#define setFrameSize(v,w,h)                     v.frame = CGRectMake(posX(v), posY(v), w, h)
#define setBoundsPosition(v,x,y)                v.bounds = CGRectMake(x, y, boundsWidth(v), boundsHeight(v))
#define setBoundsSize(v,w,h)                    v.bounds = CGRectMake(posX(v), posY(v), w, h)
#define point(x,y)                              CGPointMake(x, y)
#define append(a,b)                             [a stringByAppendingString:b];
#define distance(a,b)                           sqrtf((a-b) * (a-b))
#define animate(dur,curve,anims)                [UIView beginAnimations:nil context:NULL]; [UIView setAnimationDuration:dur]; [UIView setAnimationCurve:curve]; anims; [UIView commitAnimations]
#define addEventListener(id,s,n,o)              [[NSNotificationCenter defaultCenter] addObserver:id selector:s name:n object:o]
#define removeEventListener(id,n,o)             [[NSNotificationCenter defaultCenter] removeObserver:id name:n object:o]
#define dispatchEvent(n,o)                      [[NSNotificationCenter defaultCenter] postNotificationName:n object:o]
#define dispatchEventWithData(n,o,d)            [[NSNotificationCenter defaultCenter] postNotificationName:n object:o userInfo:d]


// User Defaults
#define boolForKey(k)                           [USER_DEFAULTS boolForKey:k]
#define floatForKey(k)                          [USER_DEFAULTS floatForKey:k]
#define integerForKey(k)                        [USER_DEFAULTS integerForKey:k]
#define objectForKey(k)                         [USER_DEFAULTS objectForKey:k]
#define doubleForKey(k)                         [USER_DEFAULTS doubleForKey:k]
#define urlForKey(k)                            [USER_DEFAULTS urlForKey:k]
#define setBoolForKey(v, k)                     [USER_DEFAULTS setBool:v forKey:k]
#define setFloatForKey(v, k)                    [USER_DEFAULTS setFloat:v forKey:k]
#define setIntegerForKey(v, k)                  [USER_DEFAULTS setInteger:v forKey:k]
#define setObjectForKey(v, k)                   [USER_DEFAULTS setObject:v forKey:k]
#define setDoubleForKey(v, k)                   [USER_DEFAULTS setDouble:v forKey:k]
#define setURLForKey(v, k)                      [USER_DEFAULTS setURL:v forKey:k]

// NSLog only in debug mode
#if DEBUG == 1
    #define Log(...) NSLog(__VA_ARGS__)
#else
    #define Log(...) do {} while (0)
#endif