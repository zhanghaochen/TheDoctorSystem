//
//  UIView+MASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASUtilities.h"
#import "MX_MASConstraintMaker.h"
#import "MX_MASViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface MAS_VIEW (MASAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_left;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_top;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_right;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_bottom;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_leading;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_trailing;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_width;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_height;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_centerX;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_centerY;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_baseline;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *(^mas_attribute)(NSLayoutAttribute attr);

#if TARGET_OS_IPHONE

@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_leftMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_rightMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_topMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_bottomMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_leadingMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_trailingMargin;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_centerXWithinMargins;
@property (nonatomic, strong, readonly) MX_MASViewAttribute *mas_centerYWithinMargins;

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)mas_closestCommonSuperview:(MAS_VIEW *)view;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)mas_makeConstraints:(void(^)(MX_MASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_updateConstraints:(void(^)(MX_MASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_remakeConstraints:(void(^)(MX_MASConstraintMaker *make))block;

@end
