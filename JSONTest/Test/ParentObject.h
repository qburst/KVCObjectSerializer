//
//  ParentObject.h
//  JSONTest
//
//  Created by mahadevan on 15/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//


#import "KVCBaseObject.h"
#import "Glossary.h"

@interface ParentObject : KVCBaseObject
{
    Glossary * glossary;
}

@property (nonatomic, retain) Glossary * glossary;
@end
