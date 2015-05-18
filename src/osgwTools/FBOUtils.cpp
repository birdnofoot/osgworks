/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * osgWorks is (C) Copyright 2009-2012 by Kenneth Mark Bryden
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

#include <osgwTools/FBOUtils.h>
#include <osgwTools/Version.h>
#include <osg/FrameBufferObject>


namespace osgwTools
{


#define OSG_FBO_CHANGE_VERSION 20906


#if OSG_MIN_VERSION_REQUIRED(3,3,3)
GLvoid glGenFramebuffers( osg::GLExtensions* fboExt, GLsizei n, GLuint* framebuffer )
#else
GLvoid glGenFramebuffers( osg::FBOExtensions* fboExt, GLsizei n, GLuint* framebuffer )
#endif
{
#if( OSGWORKS_OSG_VERSION >= OSG_FBO_CHANGE_VERSION )
    fboExt->glGenFramebuffers( n, framebuffer );
#else
    fboExt->glGenFramebuffersEXT( n, framebuffer );
#endif
}

#if OSG_MIN_VERSION_REQUIRED(3,3,3)
GLvoid glDeleteFramebuffers( osg::GLExtensions* fboExt, GLsizei n, GLuint* framebuffer )
#else
GLvoid glDeleteFramebuffers( osg::FBOExtensions* fboExt, GLsizei n, GLuint* framebuffer )
#endif
{
#if( OSGWORKS_OSG_VERSION >= OSG_FBO_CHANGE_VERSION )
    fboExt->glDeleteFramebuffers( n, framebuffer );
#else
    fboExt->glDeleteFramebuffersEXT( n, framebuffer );
#endif
}

#if OSG_MIN_VERSION_REQUIRED(3,3,3)
GLvoid glBindFramebuffer( osg::GLExtensions* fboExt, GLenum target, GLuint framebuffer )
#else
GLvoid glBindFramebuffer( osg::FBOExtensions* fboExt, GLenum target, GLuint framebuffer )
#endif
{
#if( OSGWORKS_OSG_VERSION >= OSG_FBO_CHANGE_VERSION )
    fboExt->glBindFramebuffer( target, framebuffer );
#else
    fboExt->glBindFramebufferEXT( target, framebuffer );
#endif
}


#if OSG_MIN_VERSION_REQUIRED(3,3,3)
GLvoid glFramebufferTexture2D( osg::GLExtensions* fboExt, GLenum target, GLenum attachment,
            GLenum textarget, GLuint texture, GLint level )
#else
GLvoid glFramebufferTexture2D( osg::FBOExtensions* fboExt, GLenum target, GLenum attachment,
            GLenum textarget, GLuint texture, GLint level )
#endif
{
#if( OSGWORKS_OSG_VERSION >= OSG_FBO_CHANGE_VERSION )
    fboExt->glFramebufferTexture2D( target, attachment, textarget, texture, level );
#else
    fboExt->glFramebufferTexture2DEXT( target, attachment, textarget, texture, level );
#endif
}

#if OSG_MIN_VERSION_REQUIRED(3,3,3)
GLvoid glBlitFramebuffer( osg::GLExtensions* fboExt, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
            GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter )
#else
GLvoid glBlitFramebuffer( osg::FBOExtensions* fboExt, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
            GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter )
#endif
{
#if( OSGWORKS_OSG_VERSION >= OSG_FBO_CHANGE_VERSION )
    fboExt->glBlitFramebuffer( srcX0, srcY0, srcX1, srcY1,
            dstX0, dstY0, dstX1, dstY1, mask, filter );
#else
    fboExt->glBlitFramebufferEXT( srcX0, srcY0, srcX1, srcY1,
            dstX0, dstY0, dstX1, dstY1, mask, filter );
#endif
}



// osgwTools
}
