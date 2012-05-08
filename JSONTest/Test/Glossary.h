//
//  Glossary.h
//  JSONTest
//
//  Created by mahadevan on 15/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "KVCBaseObject.h"
#import "GlossDiv.h"

@interface Glossary : KVCBaseObject
{
    GlossDiv * GlossDiv;
    NSString * title;
}
@property(nonatomic, retain) GlossDiv * GlossDiv;
@property(nonatomic, retain) NSString * title;

@end
