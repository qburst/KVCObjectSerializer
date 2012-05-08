//
//  KVCChildObject.h
//  JSONTest
//
//  Created by mahadevan on 26/10/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KVCBaseObject.h"

@interface KVCChildObject : KVCBaseObject {
    NSString * kChildName;
    NSInteger kNumValues;
}
@property (nonatomic, retain) NSString * kChildName;
@property NSInteger kNumValues;

@end
