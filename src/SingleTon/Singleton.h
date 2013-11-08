//
//  Singleton.h
//  FacebookLogin
//
//  Created by Gurpreet Singh 26/8/13.
//  Copyright (c) 2013 PrasGroup. All rights reserved.
//




#import <Foundation/Foundation.h>


// Other Classes
#import "FBConnect.h"


@protocol SingletonDelegate <NSObject>

-(void) loginReturn:(BOOL)success userInfo:(NSDictionary *)user FailWithError:(NSError *)error;

-(void) logoutReturn;


@end


@interface Singleton : NSObject <FBRequestDelegate, FBSessionDelegate, FBDialogDelegate>
{
    Facebook *facebook;

    FBRequest *postRequest, *userRequest;
}


@property (retain,nonatomic) Facebook *facebook;

@property(nonatomic,assign) id <SingletonDelegate> delegate;



+ (id) sharedManager;


- (void) logoutButtonClicked:(id)sender;

- (void) loginButtonClicked:(id)sender;


@end
