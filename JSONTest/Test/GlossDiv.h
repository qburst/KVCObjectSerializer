//
//  GlossDiv.h
//  JSONTest
//
//  Created by mahadevan on 15/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "KVCBaseObject.h"
#import "GlossList.h"

@interface GlossDiv : KVCBaseObject
{
    GlossList * GlossList;
    NSString * title;
}
@property (nonatomic, retain) GlossList * GlossList;
@property (nonatomic, retain) NSString * title;

@end
