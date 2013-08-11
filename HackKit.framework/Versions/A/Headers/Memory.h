//
//  Memory.h
//  HackKit
//
//  Created by Jeremy Ball on 8/7/13.
//  Copyright (c) 2013 Twisted Thinking. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef struct _MemoryRegion {
	pid_t _process; // The current PID
	mach_vm_address_t _address; // The current region address scanned
    mach_vm_address_t _previous; // Previous region address scanned
	mach_vm_size_t _size; // Current region size
	unsigned _attributes; // The statistics of the current region
} MemoryRegion;

// Statics values of memory region
enum _MemoryAttributes {
	MEMORY_READABLE = 1,  
	MEMORY_WRITABLE = 2,
	MEMORY_EXECUTABLE = 4
};

@interface Memory : NSObject
// Returns the struct which has information about the memory region that was just scanned
// MemoryRegion region;
// mach_vm_address_t address = 0x0;
// region = scanRegion(process,address);
MemoryRegion scanRegion(pid_t process, mach_vm_address_t address);

//  Return NSData that was contained at the memory address scanned
//  To switch this to C you could just use void if you wanted.....
//  NSData* foo = readMemory(1337,0x123456789,20);
//  NSString* value = [[[NSString alloc] initWithData:foo encoding:NSUTF8StringEncoding] autorelease];
//  NSLog(@"%@",value);
void *readMemory(pid_t process,mach_vm_address_t address,mach_vm_size_t size);

//  Write new data to the process
//  NSString * foo = @"cheat";
//  NSData * data = [foo dataUsingEncoding:NSUTF8StringEncoding];
//  writeMemory(1337,0x123456789,data);
BOOL writeMemory(pid_t process,mach_vm_address_t address,NSData *value);
BOOL writeBytesMemory(pid_t process,mach_vm_address_t address,const void *bytes,mach_vm_size_t size );

@end
