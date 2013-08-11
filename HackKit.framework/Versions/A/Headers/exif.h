//
//  exif.h
//  HackKit
//
//  Created by Jeremy Ball on 8/8/13.
//  Copyright (c) 2013 Twisted Thinking. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface exif : NSObject

@end


@interface NSString (EXIFAdditions) 
/*
    The following methods are based on Apple's ImageIO.framework.  Whatever keys ImageIO.framework supports is supported by this framework.

     Different dictionaries that are currently avialable.  Use these for the dictionary string
     
     kCGImagePropertyTIFFDictionary
     kCGImagePropertyGIFDictionary
     kCGImagePropertyJFIFDictionary
     kCGImagePropertyExifDictionary
     kCGImagePropertyPNGDictionary
     kCGImagePropertyIPTCDictionary
     kCGImagePropertyGPSDictionary
     kCGImagePropertyRawDictionary
     kCGImagePropertyCIFFDictionary
     kCGImagePropertyMakerCanonDictionary
     kCGImagePropertyMakerNikonDictionary
     kCGImagePropertyMakerMinoltaDictionary
     kCGImagePropertyMakerFujiDictionary
     kCGImagePropertyMakerOlympusDictionary
     kCGImagePropertyMakerPentaxDictionary
     kCGImageProperty8BIMDictionary
     kCGImagePropertyDNGDictionary
     kCGImagePropertyExifAuxDictionary
 
    There are way to many key words possible to list for editing / adding / delete key values.  You can get those yourself from the above dictionaries.
 
*/


// Returns all the data contained in the EXIF of a given image
// NSString * filepath = @"path/to/file";
// [filepath getEXIF];
// Returns a NSDictionary
-(NSDictionary*)getEXIF;

// Example to remove all the GPS data in an image
// NSString * filepath = @"path/to/file";
// [filepath removeSpecificEXIP:(NSString*)kCGImagePropertyGPSDictionary];
// Returns a BOOL value
- (BOOL)removeSpecificEXIF:(NSString *)dictionary;

// To create a new file without the GPS info
// NSString * filepath = @"path/to/file";
// [filepath removeSpecificEXIP:(NSString*)kCGImagePropertyGPSDictionary path:@"path/to/new/file"];
// Returns a BOOl value
- (BOOL)removeSpecificEXIF:(NSString *)dictionary path:(NSString *)newPath;

// Removes all possible EXIF data
// NSString * filepath = @"path/to/file";
// [filepath removeAllEXIF];
// Returns a BOOL value
- (BOOL)removeAllEXIF;

// Creates a new image file and removes all possible EXIF data
// NSString * filepath = @"path/to/file";
// [filepath removeAllEXIF:@"path/to/new/file"];
// Returns a BOOL value
- (BOOL)removeAllEXIF:(NSString *)newPath;

// Add / Delete/ Edit a specific key in the EXIF.
// NSString * filepath = @"path/to/file";
// NSMutableDictionary * inputDictionary  = [NSMutableDictionary dictionary];
//
// Some values can not be string so you must use NSNumber instead of a string value.
// [NSNumber numberWithInteger:1]
// or
// NSNumber * foo = [NSNumber numberWithInt:1];
//
// [inputDictionary setObject:[NSNumber numberWithInteger: 1] forKey:@"Latitude"];
// [inputDictionary setObject:@"N" forKey:@"LatitudeRef"];
// [inputDictionary setObject:foo forKey:@"Longitude"];
// [inputDictionary setObject:@"W" forKey:@"LongitudeRef"];
// [filepath editEXIF:inputDictionary dictionary:(NSString *)kCGImagePropertyGPSDictionary];
// Returns a BOOL Value
- (BOOL)editEXIF:(NSMutableDictionary *)value dictionary:(NSString *)dictionary;

// Add / Delete/ Edit a specific key in the EXIF and create a new file with the changes
// NSString * filepath = @"path/to/file";
// NSMutableDictionary * inputDictionary  = [NSMutableDictionary dictionary];
//
// Some values can not be string so you must use NSNumber instead of a string value.
// [NSNumber numberWithInteger:1]
// or
// NSNumber * foo = [NSNumber numberWithInt:1];
//
// [inputDictionary setObject:[NSNumber numberWithInteger: 1] forKey:@"Latitude"];
// [inputDictionary setObject:@"N" forKey:@"LatitudeRef"];
// [inputDictionary setObject:foo forKey:@"Longitude"];
// [inputDictionary setObject:@"W" forKey:@"LongitudeRef"];
// [filepath editEXIF:inputDictionary dictionary:(NSString *)kCGImagePropertyGPSDictionary path:@"path/to/new/file"];
// Returns a BOOL Value
- (BOOL)editEXIF:(NSMutableDictionary *)value dictionary:(NSString *)dictionary path:(NSString *)newPath;

// Returns the hex of the image file for those who want to manually search for the EXIF values
// NSString * filepath = @"path/to/file";
// NSdate * foo = [filepath imageData];
// returns NSData
- (NSData*)imageData;
@end