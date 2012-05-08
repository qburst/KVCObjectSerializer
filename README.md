Features
--------
1. Serialize NSObject classes to NSDictionary types or JSON ( possibly to XML or PLIST )
2. DeSerialize JSON / NSDictionary classes back to NSObject model classes.
3. Specify property names for NSObjects while deserializing from JSON or NSDictionary keys.
3. Multi level recursion supported for both Serialization and Deserialzation
4. Ability to serialize and deserialize NSArray properties also.

HOW TO
------
1. Copy the two files KVCBaseObject.h and KVCBaseObject.m to your project folder.
2. Subclass your model objects from KVCBaseObject and you are good to go!

Examples
--------
1. Serialize an NSOBject to JSON / Dictionary
---------------------------------------------
Check out the sample KVCTestObject and KVCChildObject model classes included in the sample project.

  // KVCTestObject

        #import <Foundation/Foundation.h>
        #import "KVCChildObject.h"
        #import "KVCBaseObject.h"

        @interface KVCTestObject : KVCBaseObject {
            NSString * kName;
            NSString * addressField;
            NSInteger kAge;
            NSMutableArray * kChildrenArray;  
            NSDictionary * kChildObject;
            BOOL isAvailable;
            double doubleValue;
            
        }
        @property BOOL isAvailable;
        @property double doubleValue;
        @property (nonatomic, retain) NSString  * kName;
        @property (nonatomic, retain) NSString * addressField;
        @property NSInteger kAge;
        @property (nonatomic, retain) NSMutableArray * kChildrenArray;
        @property (nonatomic, retain) NSDictionary * kChildObject;
        @end

        // KVCTestObject.m
        #import "KVCTestObject.h"

        @implementation KVCTestObject

        @synthesize isAvailable;
        @synthesize kName;
        @synthesize kAge;
        @synthesize addressField;
        @synthesize kChildrenArray;
        @synthesize kChildObject;
        @synthesize doubleValue;

        -(id) init {
            if (self = [super init]) {

            }
            return self;   
        }

        /*
         * Overriden method of KVCBaseObject to specify type of object that is to
         * be created inside the array kChildrenArray. If left unspecified, the
         * deserializer will simply copy the dictionary objects to kChildrenArray.
         */
        - (NSString *)getComponentTypeForCollection:(NSString *)propertyName {
            if ([propertyName isEqualToString:@"kChildrenArray"]) {
                return @"KVCChildObject";
            }
            return nil;
        }

        /*
         * There is no matching property for the json key "kAddress"
         * Therefore implement the below method to specify property name to 
         * use for unspecified keys.
         */
        -(NSString *)getPropertyNameForJsonKey:(NSString *)jsonKey {
            if ([jsonKey isEqualToString:@"kAddress"]) {
                return @"addressField";
            } else if ([jsonKey isEqualToString:@"kAvailable"]) {
                return @"isAvailable";
            }
            return nil;
        }
        @end

        // KVCChildObject.h
        #import <Foundation/Foundation.h>
        #import "KVCBaseObject.h"

        @interface KVCChildObject : KVCBaseObject {
            NSString * kChildName;
            NSInteger kNumValues;
        }
        @property (nonatomic, retain) NSString * kChildName;
        @property NSInteger kNumValues;

        @end

        // KVCChildObject.m
        #import "KVCChildObject.h"

        @implementation KVCChildObject

        @synthesize kNumValues;
        @synthesize kChildName;

        @end

2. Usage
--------
2.1 To serialize KVCTestObject, simply call

	KVCTestObject * obj = [[KVCTestObject alloc] init];
	obj.kame = @"Test name";
	NSDictionary * serializedDictionary = [obj objectToDictionary];
	NSString * jsonString = [obj objectToJson];

2.2 To Deserialize a JSON / Dictionary to KVCTestObject, call

    NSString * jString = @"{\"kName\" : \"Test name\",\
                            \"kAddress\" : \"Test Addr\",\
                            \"kAge\" : 39, \
                            \"kChildrenArray\" : \
                           [ { \"kChildName\" : \"child1\", \"kNumValues\" : 32}, \
                             { \"kChildName\" : \"child2\", \"kNumValues\" : 17} ], \
                            \"kChildObject\" : { \"kChildName\" : \"qweqwe\", \"kNumValues\" : 4}, \
                            \"kAvailable\" : 1}";


	KVCTestObject * obj = (KVCTestObject *)[KVCTestObject 	objectForJSON:jString];

-------------

3. Note 
-------
If your models are made up of NSManagedObjects ( Core Data Objects ), you might want to checkout the comments at
 + (NSMutableDictionary *) getPropertiesAndTypesForClassName:(const char *)className in the file KVCBaseObject.m 
for some tweaks!

This library was written by mahadevan@qburst.com for internal usage purposes