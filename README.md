# Week 3 09/11/2023 Progress Report
## Reflections 
[Watch my Youtube Video explanation Here](https://youtu.be/fW_C_lz0i7k)

I wanted to continue working on something that protected me from the sun this week, and I was inspired by my recent purchase of some sunglasses that do not quite fit my face perfectly. It was hard to tell the sizing on their website and I need to get a new pair that truly fits my face. I really liked the funky design on the pair that I purchased, so I wanted to create something that was equally fun and still provided enough customization to allow for a perfect fit on my face. I really wanted to challenge myself as I had never coded anything from scratch in grasshopper, so I wanted to move away from the phone stand and start building something that was completely unique. I have done a lot of 3D printing and laser cutting as well, so I wanted to put a lot more time into the code and skip out on creating something physical. 

![Image of Finished Sunglasses](Media/Sunglasses/FinishedGlasses.jpg)

I started with creating the frames of the glasses. Orignally, I had created cylindrical frames as I had not yet discovered the polygon tool yet. I found it easy to create the objects and then remove the material from the center, but the first challenge I ran into was creating the bridge of the glasses. I knew I wanted to have the bridge be able to move up and down in relation to the frames, but as I changed the Z component of the box, I saw that there were gaps between the bridge and frame. I had orignally set the origin of the box to be on the tangent edge of the frames, but this always left a gap. I had already created the cutout for the lens at this point, so I was trying to play with a way to keep the origin within the frame material, but this still left me with gaps as it moved farther up. To fix this issue, I realized that I could move the origin of the box to the center of the frame, combine it with uncut frame, and then create the cutout. This gave the bridge enough length to always be connected to the frame and move up and down with any gaps. 

![Original Lens Shape](Media/Sunglasses/LensShape.jpg)
![Added Bridge to Frame](Media/Sunglasses/FrameBridgeUnion.jpg)
![Cutout Added to Frame](Media/Sunglasses/FrameBridgeCutout.jpg)

When I moved onto the arms of the glasses, I realized that I would have the same issue as with the bridge, so I decided to just start by creating my base shape in the middle of the glasses right away. I knew that I wanted to use the sweep function to create a more natural looking arm shape. I discovered the polygon tool at this point, and knew that I wanted the shape of the arm to be customizable to have shapes that ranged from triangles to octogons. I then created my points for the sweep and linked all of them to have the same Z component as the bridge of the glasses so that they moved in unison. For two of the points in the middle of the array, I gave them an extra slider that allowed for further movement in the Z direction. Once I had all of my points, I created the sweep with the base polygon. This extended from the middle of the frames. I tried to combine this in the merge block that I used with the brige and frames, but it did not seem to work. I eventually had to create another merge and union block before substracting the cutout from the frames. This worked, but created a linkage visual in the code that I was unsure about and had to lookup. This double dashed line meant that multiple lists of data items are transferred between the blocks. 

![Points created for Arm Sweep](Media/Sunglasses/SweepPoints.jpg)
![Completed Sweep](Media/Sunglasses/SweepComplete.jpg)
![Merge blocks code with double dashed lines](Media/Sunglasses/MergeCode.jpg)

The arms were extruding correctly, but had a little bit excess material that was outside of the thickness of the frames. In order to get rid of this, I needed to move the origin of the cutout to be farther in the frames so that it cut out everything. This worked well and covered all of the potential shapes that I had allowed the users to choose.  

![Eye Holes Cut out](Media/Sunglasses/EyeCutout.jpg)

My final challenge is getting the frame to mirror to create the other side of the glasses. To make things simpler for myself and to reduce the redundancy, I wanted to only model half of the frames and then try to mirror them across a plane that was coincident with the inside edge of the bridge. However, because I was allowing the bridge to change length, I could not create a static plane to input into the mirroring function. I needed to find a way to construct a plane that always existed on the surface of the bridge. After some searching around, I found that I could deconstruct Breps and pick out certain vertices on the object. I was able to use this to find three vertices on the edge of the brep and then input those into the plane function. This plane would always take in my points when they changed and stayed on the right surface of the bridge. With this mirroring, I was able to construct only half the frame and reduce a lot of the work I orignally thought I was needing to do. 

![Mirroring Plane Code](Media/Sunglasses/MirroringPlaneCode.jpg)
![Mirror Plane Shown](Media/Sunglasses/MirroringPlane.jpg)
![Full Mirrored Sunglasses Frame](Media/Sunglasses/MirroredFull.jpg)

With all of this completed, I was able to create a fully functioning model of customizable sunglasses. The video linked at the beginning of the report shows all of the functionality, and the grasshopper file is located [here](Media/Sunglasses/sunglasses.gh) as well.

![Full Code PNG](Media/Sunglasses/ProjectOneFullCode.png)

# Week 2 09/04/2023 Progress Report
## Reflections 
This week I wanted to focus on becoming more familiar with the parametric modeling in Grasshopper. As I have made my way from the Midwest to Sunny California, I have noticed that the need for shade is vastly higher, not only for me but for my phone as well. I wanted to play with the idea of adding a little umbrella to the model, not for anything truly practical but more for fun. The goal was to have mesh a cone and cylinder together to create the umbrella shape and then have it rotate around the phone stand as the viewing angle of the phone also changed. My original idea for this week was to add a party hat to the stand because it looked somewhat head-shaped, but after playing around with the settings of the cone and trying to align it to the sphere, I saw that it could be used as an umbrella and went forward with that idea. The ultimate goal would be to have an umbrella that never collides with the phone, meshes perfectly into the base of the stand, and is fully adjustable in height and size. 

Using the simplified model provided by TJ, I started to play around with the settings of the phone stand itself to generate something that fit my phone and looked good to me. Once I had that shape, I began working on constructing the cone in Grasshopper. Ideally, the distance from the bottom edge of the cone to the phone should adjust as the dimensions of the phone change, but as my grasshopper became more and more complex, I feel like I need to clean up and reorganize before I draw too much information from the phone so that my code is still readable. I eventually ended up just using a slider to adjust the height of the cone away from the sphere. I had to generate vectors to adjust the origin of the cone because I figured that the shading of the phone could be done with multiple angles, not just directly over the phone. I used the following segment of code to do that. 

![Grasshopper Code that shows the vector coding][VectorTransform]

That allowed me to move the cone however I wanted in a single orientation, but I needed to change the angle of the cone so that as the phone viewing angle changed, the umbrella would not interfere with the spot where the phone rested in the stand. Using a rotation block, I inputted the phone viewing angle, learned I needed to convert to radians after awhile, and then outputted the rotated geometry. Once, I did this, I realized that the viewing angle was the angle of the phone face relative to the table and not the angle of the body to the table, so I needed to subtract 90 degrees in order for the cone to be orthogonal to the phone screen face. Once I did this, the cone mimicked the angle of the phone and moved smoothly with the changes in the angles. 

![Cone Changing Angles](Media/ConeOnlyAngleOne.jpg)

![Cone Changing Angles 2](Media/ConeOnlyAngleTwo.jpg)

I repeated this process for the pole of the umbrella, which consisted of just a thin cylinder that originated at the base of the stand. The length of the pole is derived from the Z height of the cone. The rotation was copied from the cone, but I noticed that the end of the cylinder was poking out the underside of the phone base, so I needed to copy the rectangular void that created the table surface and then add another shape difference to make sure that the flat plane remained on the bottom of the stand. One issue that I am still working through is connecting the pole and cone to be one object. I need to work out the height mathematically so that the pole always touches the cone but does not go through it. Then once this is fixed I will create a shape union to combine the umbrella with the base of the phone stand. 

![Full Umbrella Moving Angles](Media/UmbrellaAssembled.jpg)

![Full Umbrella Moveing at Different Angle](Media/DifferentAngleStand.jpg)

## Speculations
I think that this week gave me a good insight into the mechanics of Grasshopper and what I could do with it. If I were to keep moving forward with the umbrella on the phone stand and create something somewhat useful, I would want to limit the angle of movement of the umbrella so that it remained mostly overhead of the phone as the phone tilted. This way there could still be a response to changes in the viewing angle, but the shade remains mostly overhead. I would also like to change the position of the pole to be located on the stand to be off to the side. This way the pole would not interfere with inserting or removing the phone from the stand. There would be a lot of use to have the umbrella removable as well, as it is not always necessary and would get in the way of photos or videos from the phone. 


# Week 1 08/30/2023 Progress Report
## Reflections
This week was the first week I had ever used Rhino. I came into it thinking it would be similar to other CAD software I've used like Solidworks or Fusion but it was different enough to challenge me. I jumped right into picking apart the cell phone stand file with everything in it because I wanted to see the entire file and how everything fit in. This was a bit overwhelming but I began to pick up on how Rhino and Grasshopper worked. 

I learned a lot about the visual coding system of grasshopper, and while I don't completely understand all of the functions within the file, I understand how things need to connect and how the use of sliders can allow for this became a generative design tool. I was able to use the sliders to generate the visuals of a stand that I wanted to use. I measured my own phone in order to do this, but I got stuck when trying to export the drawings to something that I could use on the laser cutter. I would be able to export the files by selecting them and then using the export command, but often the scale of my parts would be incorrect. Eventually I had to manually resize the bounding box in order to resize the parts correctly. 
The biggest thing I started to learn this week was how parametric modeling could be done in Rhino. The tutorial from TJ helped a lot, but only after I spent about 2 hours parsing through the visual code did I really begin to understand what happened in the file. I do not enjoy learning code like this, but it helped me play around and break the file so that I did understand some of the functions of the files. 

Once I had the file, taking it to laser cut was not much of an issue. As I have lots of experience with laser cutting, the ones in the Makerspace were not too bad. I was able to make a few test cuts with the default settings for plywood, and after a few adjustments my pieces cut out from the scrap perfectly and fit together very well. 

![Laser Cutting the Phone Stand](Media/laserCuttingStand.jpg)

Overall, I think this was definitely more challenging than I had imagined, and I know I have a long way to go to understand something this complex but I have gotten a lot of knowledge from this so far. I think I will need to have more instruction to become better at Rhino and Grasshopper. I was able to laser cut a model of the phone stand with some modifications for my phone, and it seemed to work pretty well and fit my phone correctly. 

![Fully Assembled Phone Stand from Side View](Media/StandAssembled.jpg)
![Fully Assembled Phone Stand from Front View](Media/StandAssembledFront.jpg)

## Speculations
I think that as tools like 3D printing and laser cutting get faster and become more accessible, parametric modeling will allow for customization to become common practice in goods. I could imagine something like this, where a company would sell the software, and a user would be able to easily customize a product to their exact needs and produce it in their own home. My hope is that this could potentially create less waste from inaccurate or generic sizing of certain products. If we could generate items such as clothing or shoes that would be custom fit for someone, they could last much longer and have better quality and value to the consumer. This would go against the subscription model of many goods, but it could be a necessary shift to stop meaningless overproduction and waste.  

This tool also reminds me of the article we discussed in Debates in Design by Kate Compton about Casual Creators. Compton discusses tools that help people design and create objects in a way that is much faster and enjoyable for the user. Casual creators don't require lots of training or time for the user to understand how to create, and they give users lots of power to create within some predefined limits established by the tool. There is not a lot of knowledge needed to make the phone stand with this tool. If the interface was made so that the sliders were easy to move and could handle some written input, then this could be considered a casual creator because of how easy it is to create your own design in the model. 

[VectorTransform]: Media/VectorTransformation.jpg
