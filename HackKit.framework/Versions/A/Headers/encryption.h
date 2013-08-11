//
//  encryption.h
//  HackKit
//
//  Created by Jeremy Ball on 8/9/13.
//  Copyright (c) 2013 Twisted Thinking. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface encryption : NSObject

@end



@interface NSString (EncryptionAdditions) 

// Returns the MD2 value of the string
// NSString * hash = [@"string" MD2String];
// Returns an NSString
-(NSString*)MD2String;

// Returns the MD4 value of the string
// NSString * hash = [@"string" MD4String];
// Returns an NSString
-(NSString*)MD4String;

// Returns the MD5 value of the string
// NSString * hash = [@"string" MD5String];
// Returns an NSString
-(NSString*)MD5String;

// Returns the SHA1 value of the string
// NSString * hash = [@"string" SHA1String];
// Returns an NSString
-(NSString*)SHA1String;

// Returns the SHA224 value of the string
// NSString * hash = [@"string" SHA224String];
// Returns an NSString
-(NSString*)SHA224String;

// Returns the SHA256 value of the string
// NSString * hash = [@"string" SHA256String];
// Returns an NSString
-(NSString*)SHA256String;

// Returns the SHA384 value of the string
// NSString * hash = [@"string" SHA384String];
// Returns an NSString
-(NSString*)SHA384String;

// Returns the SHA512 value of the string
// NSString * hash = [@"string" SHA512String];
// Returns an NSString
-(NSString*)SHA512String;


@end

@interface NSData (AESAdditions)
// Standard encryption and decryption with a key
// If you do not wish to include <CommonCrypto/CommonDigest.h> && <CommonCrypto/CommonCryptor.h> you can pass the int values
// I was nice and provided the int values if you do not know where to find them.

// keySize Values
// kCCKeySizeAES128    = 16
// kCCKeySizeAES192    = 24
// kCCKeySizeAES256    = 32
// kCCKeySizeDES       = 8
// kCCKeySize3DES      = 24
// kCCKeySizeMinCAST   = 5
// kCCKeySizeMaxCAST   = 16
// kCCKeySizeMinRC4    = 1
// kCCKeySizeMaxRC4    = 512
// kCCKeySizeMinRC2    = 1
// kCCKeySizeMaxRC2    = 128

// blockSize Values
// kCCBlockSizeAES128  = 16
/* DES */
// kCCBlockSizeDES     = 8
/* 3DES */
// kCCBlockSize3DES    = 8
/* CAST */
// kCCBlockSizeCAST    = 8
// kCCBlockSizeRC2     = 8

// algorithm Values
// kCCAlgorithmAES128   = 0
// kCCAlgorithmDES      = 1
// kCCAlgorithm3DES     = 2  
// kCCAlgorithmCAST     = 3
// kCCAlgorithmRC4      = 4
// kCCAlgorithmRC2      = 5

// Returns the encrypted NSData
// NSString * str = @"hello world";
// NSData* data = [str dataUsingEncoding:NSUTF8StringEncoding];
// [data encrypt:@"password" keySize:kCCKeySizeAES256 blockSize:kCCBlockSizeAES128 algorithm:kCCAlgorithmAES128];
// or
// [data encrypt:@"password" keySize:32 blockSize:16 algorithm:0];
// Returns NSData
- (NSData *)encrypt:(NSString *)key keySize:(int)keySize blockSize:(int)blockSize algorithm:(int)algorithm;


// Returns the decrypted NSData
// NSString * str = @"hello world";
// NSData* data = [str dataUsingEncoding:NSUTF8StringEncoding];
// NSString * str = [[NSString alloc] initWithData:[data decrypt:@"password" keySize:kCCKeySizeAES256 blockSize:kCCBlockSizeAES128 algorithm:kCCAlgorithmAES128] encoding:NSUTF8StringEncoding];
// or
// NSString * str = [[NSString alloc] initWithData:[data decrypt:@"password" keySize:32 blockSize:16 algorithm:0] encoding:NSUTF8StringEncoding];
// Returns NSData
- (NSData *)decrypt:(NSString *)key keySize:(int)keySize blockSize:(int)blockSize algorithm:(int)algorithm;
@end