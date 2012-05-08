//
//  QBViewController.m
//  JSONTest
//
//  Created by mahadevan on 26/10/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "QBViewController.h"

#import "KVCTestObject.h"
#import "JSON.h"
#import "objc/runtime.h"
#import "ParentObject.h"

@implementation QBViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{    
    [super viewDidLoad];
    /*
     * Reads the sample json from the file 'sample_json.txt' and converts it to object.
     */
    NSError * error;
    NSString * jsonString = [[NSString alloc] initWithContentsOfFile:
                            [[NSBundle mainBundle] pathForResource:@"sample_json" ofType:@"txt"]  encoding:NSUTF8StringEncoding error:&error];
    ParentObject * parent = (ParentObject*)[ParentObject objectForJSON:jsonString];    
    NSLog(@"%@",[parent objectToJson]);
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

@end
