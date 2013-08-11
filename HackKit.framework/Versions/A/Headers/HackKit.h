//
//  HackKit.h
//  HackKit
//
//  Created by Jeremy Ball on 8/5/13.
//  Copyright (c) 2013 Twisted Thinking. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HackKit : NSObject
// Get application name
// NSString * foo = [HackKit theApp];
// Returns NSString
+(NSString *)theApp;

// Throws an alert window
// [HackKit alert:@"Sorry bro, some shit went wrong"];
+(void)alert:(NSString *)string;

// Returns the task number for the pid
// vm_map_t foo = getTask(1337);
// Returns vm_map_t
vm_map_t getTask(pid_t thePID);
@end


@interface NSString (HackKitAdditions) 
// Returns a string with chars or strings removed from it
// NSString * foo = [@"Hello friend" strRemove:@"friend" : @"World"];
// Returns an NSString
- (NSString *)strRemove:(NSString*)search:(NSString*)replace;

// Searchs a string for another string
// [@"Hello World" stringContain:@"World];
// Returns a BOOL Value
- (BOOL)stringContain:(NSString *)inputStr;

// Searchs a string for another string with an option of case sensative or case insensative
// [@"Hello World" stringContain:@"World option:NSCaseInsensitiveSearch];
// Returns a BOOL Value
- (BOOL)stringContain:(NSString *)inputStr option:(NSStringCompareOptions)option;
@end