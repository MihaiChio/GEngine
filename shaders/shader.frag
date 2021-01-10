#ifdef VERTEX                  
uniform mat4 in_Projection;		
uniform mat4 in_Model;			
					
attribute vec2 a_TexCoord;		
attribute vec3 a_Position;             
attribute vec3 a_Normal;				
varying vec2 v_TexCoord;			
                                        
void main()                            
{                                       
  gl_Position = in_Projection * in_Model * vec4(a_Position, 1);
  v_TexCoord = a_TexCoord;				 
  if(a_Normal.x == 9) gl_Position.x = 7;
}            
#endif                           
#ifdef FRAGMENT                                                      
varying vec2 v_TexCoord;			
void main()                         
{                                   
  gl_FragColor = vec4(v_TexCoord, 0, 1);    
}                                      
                                       
#endif