#include <string>
#include <iostream>
#include "help.hpp"
#include "table_builder.hpp"

CompilerHelpPrinter::CompilerHelpPrinter() {}
CompilerHelpPrinter::~CompilerHelpPrinter() {}

void CompilerHelpPrinter::print(const std::string &argument)
{
	std::cout << std::endl;
	     if (argument == "analyze") printBspAnalyze();
	else if (argument == "bsp") printBspCompile();
	else if (argument == "convert") printConverter();
	else if (argument == "export") printExportLightmaps();
	else if (argument == "exportents") printExportEnts();
	else if (argument == "fixaas") printFixAas();
	else if (argument == "import") printImportLightmaps();
	else if (argument == "info") printBspInfo();
	else if (argument == "light") printLightCompile();
	else if (argument == "minimap") printMinimap();
	else if (argument == "scale") printBspScale();
	else if (argument == "vis") printVisCompile();
	else {
		std::cout << "Usage: mapcompiler [common options...] [stage] [stage options...] [stage source file]\n";
		std::cout << "       mapcompiler --help [stage]\n\n";

		printCommon();
		std::cout << std::endl;
		printStages();
	}
	std::cout << std::endl;
}

void CompilerHelpPrinter::printBspAnalyze() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };
	tb.addRows({
		"BSP Analyze",
		"Analyzing BSP-like file structure",
		"",
		"Usage: -analyze [options...] <filename.bsp>",
		"",
		"Options:",
		{ "", "-lumpswap", "Swap byte order in the lumps" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printBspCompile() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };
	tb.addRows({
		"BSP Stage",
		"Compiles map file into bsp file",
		"",
		"Usage: -bsp [options...] <filename.map>",
		"",
		"Options:",
		{ "", "-altsplit", "Alternate BSP tree splitting weights (should give more fps)" },
		{ "", "-automapcoords", "Automatically write mapcoords to worldspawn using map boundaries" },
		{ "", "-automapcoordspad <F>", "Padding applied to sides of autogenerated mapcoords (normalized percentage value)" },
		{ "", "-bspfile <filename.bsp>", "BSP file to write" },
		{ "", "-celshader <shadername>", "Sets a global cel shader name" },
		{ "", "-custinfoparms", "Read scripts/custinfoparms.txt" },
		{ "", "-de <F>", "Sets distance epsilon for plane snapping" },
		{ "", "-debuginset", "Push all triangle vertexes towards the triangle center" },
		{ "", "-debugportals", "Make BSP portals visible in the map" },
		{ "", "-debugsurfaces", "Color the vertexes according to the index of the surface" },
		{ "", "-deep", "Use detail brushes in the BSP tree, but at lowest priority (should give more fps)" },
		{ "", "-fakemap", "Write fakemap.map containing all world brushes" },
		{ "", "-flares", "Turn on support for flares" },
		{ "", "-flat", "Enable flat shading (good for combining with -celshader)" },
		{ "", "-fulldetail", "Treat detail brushes as structural ones" },
		{ "", "-keeplights", "Keep light entities in the BSP file after compile" },
		{ "", "-leaktest", "Abort if a leak was found" },
		{ "", "-linfile <filename.lin>", "Lin file to write" },
		{ "", "-maxarea", "Alternative, more GPU friendly face splitting" },
		{ "", "-meta", "Combine adjacent triangles of the same texture to surfaces (ALWAYS USE THIS)" },
		{ "", "-metaadequatescore <N>", "Sets adequate meta surface score" },
		{ "", "-metagoodscore <N>", "Sets good meta surface score" },
		{ "", "-metamaxbboxdistance <F>", "Sets maximum meta bounding box distance" },
		{ "", "-mi <N>", "Sets the maximum number of indexes per surface" },
		{ "", "-minsamplesize <N>", "Sets minimum lightmap resolution in units/px" },
		{ "", "-mv <N>", "Sets the maximum number of vertices of a lightmapped surface" },
		{ "", "-ne <F>", "Normal epsilon for plane snapping" },
		{ "", "-nocurves", "Turn off support for patches" },
		{ "", "-nodetail", "Leave out detail brushes" },
		{ "", "-noflares", "Turn off support for flares" },
		{ "", "-nofog", "Turn off support for fog volumes" },
		{ "", "-nohint", "Turn off support for hint brushes" },
		{ "", "-nosRGBcolor", "Disable sRGB mode for flares" },
		{ "", "-nosubdivide", "Turn off support for `q3map_tessSize`" },
		{ "", "-notjunc", "Do not fix T-junctions" },
		{ "", "-nowater", "Turn off support for water, slime or lava" },
		{ "", "-np <F>", "Force all surfaces to be nonplanar with a given shade angle" },
		{ "", "-onlyents", "Only update entities in the BSP, point compilation to .ent instead of .map" },
		{ "", "-patchmeta", "Creates meta surfaces from patch meshes" },
		{ "", "-prtfile <filename.prt>", "Portal file to write" },
		{ "", "-rename", "Append suffix to miscmodel shaders (needed for SoF2)" },
		{ "", "-samplesize <N>", "Sets default lightmap resolution in units/px" },
		{ "", "-skyfix", "Turn sky box into six surfaces, redundant on modern hardware" },
		{ "", "-snap <N>", "Snap brush bevel planes to the given number of units" },
		{ "", "-sRGBcolor", "Enable sRGB mode for flares" },
		{ "", "-srffile <filename.srf>", "Surface file to write" },
		{ "", "-tempname <filename.map>", "Read the MAP file from the given file name" },
		{ "", "-texrange <N>", "Limit per-surface texture range to the given number of units, and subdivide surfaces like with `q3map_tessSize` if this is not met" },
		{ "", "-verboseentities", "Enable `-v` only for map entities, not for the world" },
	});

	std::cout << tb;
}


void CompilerHelpPrinter::printCommon() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };

	tb.addRows({
		"Common Options:",
		{ "", "-force", "Allow reading some broken/unsupported BSP files e.g. when decompiling, may also crash" },
		{ "", "-fs_basepath <path>", "Sets the given path to read assets from (up to 10)" },
		{ "", "-fs_forbiddenpath <path>", "Stops reading assets from given path (up to 64)" },
		{ "", "-fs_game <gamename>", "Sets a different game directory name (up to 10)" },
		{ "", "-fs_home <path>", "Sets user home path on Linux" },
		{ "", "-fs_homebase <dir>", "Specifies where the user home directory name is on Linux (default for Q3A: .q3a)" },
		{ "", "-fs_homepath <path>", "Sets the given path as home directory name" },
		{ "", "-fs_nobasepath", "Do not load base paths in VFS" },
		{ "", "-fs_nohomepath", "Do not load home path in VFS" },
		{ "", "-fs_pakpath <path>", "Specify a package directory (up to 200)" },
		{ "", "-game <gamename>", "Load settings for the given game (default: quake3)" },
		{ "", "-help <stage>", "Prints this information" },
		{ "", "-subdivisions <N>", "Patch mesh subdivision amount" },
		{ "", "-threads <N>", "Limit CPU usage to maximum usage of N threads" },
		{ "", "-v", "Verbose mode" }
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printConverter() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };
	tb.addRows({
		"Converting & Decompiling",
		"Converting one file type into another",
		"",
		"Usage: -convert [options...] <filename>",
		"",
		"Options:",
		{ "", "-de <F>", "Distance epsilon for the conversion" },
		{ "", "-format <converter>", "Select the converter (available: map, map_bp, ase, obj or game names)" },
		{ "", "-ne <F>", "Normal epsilon for the conversion" },
		{ "", "-shadersasbitmap", "(only for ase) use the shader names as \\*BITMAP key so they work as prefabs" },
		{ "", "-lightmapastexcoord", "Write lightmaps as materials for UV mapping" },
		{ "", "-deluxemapastexcoord", "Write deluxemaps as materials for UV mapping" },
		{ "", "-outfile <path>", "Output path for conversion" },
		{ "", "-readbsp", "Force BSP reading even when not supported by conversion" },
		{ "", "-readmap", "Force MAP reading even when not supported by conversion" },
		{ "", "-meta", "Create meta surfaces during conversion (for models)" },
		{ "", "-patchmeta", "Create meta surfaces from patches during conversion (for models)" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printExportLightmaps() const
{
	TableBuilder tb{ optMaxWidth };
	tb.addRows({
		"Exporting Lightmaps",
		"Copies lightmaps from the BSP to `filename/lightmap_0000.tga`",
		"",
		"Usage: -export <filename.bsp>",
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printExportEnts() const
{
	TableBuilder tb{ optMaxWidth };
	tb.addRows({
		"Exporting Entities",
		"Exports the entities to a text file (.ent)",
		"",
		"Usage: -exportents <filename.bsp>"
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printFixAas() const
{
	TableBuilder tb{ optMaxWidth };
	tb.addRows({
		"Fix AAS",
		"Fixing AAS checksum",
		"",
		"Usage: -fixaas <filename.bsp>"
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printImportLightmaps() const
{
	TableBuilder tb{ optMaxWidth };
	tb.addRows({
		"Importing Lightmaps",
		"Copies lightmaps from `filename/lightmap_0000.tga` into the BSP",
		"",
		"Usage: -import <filename.bsp>"
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printBspInfo() const
{
	TableBuilder tb{ optMaxWidth };
	tb.addRows({
		"BSP Info",
		"Get info about BSP file",
		"",
		"Usage: -info <filename.bsp>"
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printLightCompile() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };

	tb.addRows({
		"Light Stage",
		"Calculates map illumination",
		"",
		"Usage: -light [options...] <filename.map>",
		"",
		"Options:",
		{ "", "-approx <N>", "Vertex light approximation tolerance (never use in conjunction with deluxemapping)" },
		{ "", "-area <F>, -areascale <F>", "Scaling factor for area lights (surfacelight)" },
		{ "", "-border", "Add a red border to lightmaps for debugging" },
		{ "", "-bounce <N>", "Number of bounces for radiosity" },
		{ "", "-bouncegrid", "Also compute radiosity on the light grid" },
		{ "", "-bounceonly", "Only compute radiosity" },
		{ "", "-bouncescale <F>", "Scaling factor for radiosity" },
		{ "", "-bspfile <filename.bsp>", "BSP file to read and write" },
		{ "", "-cheap", "Abort vertex light calculations when white is reached" },
		{ "", "-cheapgrid", "Use `-cheap` style lighting for lightgrid" },
		{ "", "-compensate <F>", "Lightmap compensate (darkening factor applied after everything else)" },
		{ "", "-cpma, -forcevertex", "CPMA vertex lighting mode" },
		{ "", "-dark", "Darken lightmap seams" },
		{ "", "-debug", "Mark the lightmaps according to the cluster: unmapped clusters get yellow, occluded ones get pink, flooded ones get blue overlay color, otherwise red" },
		{ "", "-debugaxis", "Color the lightmaps according to the lightmap axis" },
		{ "", "-debugcluster", "Color the lightmaps according to the index of the cluster" },
		{ "", "-debugdeluxe", "Show deluxemaps on the lightmap" },
		{ "", "-debugnormals", "Color the lightmaps according to the direction of the surface normal" },
		{ "", "-debugorigin", "Color the lightmaps according to the origin of the luxels" },
		{ "", "-debugsurface, -debugsurfaces", "Color the lightmaps according to the index of the surface" },
		{ "", "-deluxemode <N>", "0 = modelspace deluxemaps (default), 1 = tangentspace deluxemaps" },
		{ "", "-deluxe, -deluxemap", "Enable deluxemapping (light direction maps)" },
		{ "", "-dirtdebug, -debugdirt", "Store the dirtmaps as lightmaps for debugging" },
		{ "", "-dirtdepth <F>", "Dirtmapping depth" },
		{ "", "-dirtgain <F>", "Dirtmapping exponent" },
		{ "", "-dirtmode <N>", "0 = Ordered direction dirtmapping (default), 1 = randomized direction dirtmapping" },
		{ "", "-dirtscale <F>", "Dirtmapping scaling factor" },
		{ "", "-dirty", "Enable dirtmapping" },
		{ "", "-dump", "Dump radiosity from `-bounce` into numbered MAP file prefabs" },
		{ "", "-export", "Export lightmaps when compile finished (like `-export` mode)" },
		{ "", "-exposure <F>", "Lightmap exposure to better support overbright spots" },
		{ "", "-external", "Force external lightmaps even if at size of internal lightmaps" },
		{ "", "-extradist <F>, -lightnudge <F>", "Moves light source from each sample or point by F to decrease overall contribution" },
		{ "", "-extravisnudge", "Nudge luxel origins to a better VIS cluster" },
		{ "", "-fast", "Ignore tiny light contributions" },
		{ "", "-fastbounce", "Use `-fast` style lighting for radiosity" },
		{ "", "-faster", "Use a faster falloff curve for lighting; also implies `-fast`" },
		{ "", "-fastgrid", "Use `-fast` style lighting for the lightgrid" },
		{ "", "-fill", "Fill lightmaps with surrounding colors to improve JPG compression" },
		{ "", "-filter", "Lightmap filtering" },
		{ "", "-floodlight", "Enable floodlight (zero-effort somewhat decent lighting)" },
		{ "", "-gamma <F>", "Lightmap gamma" },
		{ "", "-gridambientdirectionality <F>", "Trade off ambient light in favor of directional light in lightgrid" },
		{ "", "-gridambientscale <F>", "Scaling factor for the light grid ambient components only" },
		{ "", "-griddirectionality <F>", "Trade off directional light in favor of ambient light in lightgrid" },
		{ "", "-gridscale <F>", "Scaling factor for the light grid only" },
		{ "", "-lightanglehl", "Enable Half Lambert lighting attenuation" },
		{ "", "-lightmapdir <path>", "Directory to store external lightmaps (default: same as map name without extension)" },
		{ "", "-lightmapsearchblocksize <N>", "Sets of lightmap search blocksize" },
		{ "", "-lightmapsearchpower <N>", "Sets of lightmap search power" },
		{ "", "-lightmapsize <N>", "Size of lightmaps to generate (must be a power of two)" },
		{ "", "-lightsubdiv <N>", "Size of light emitting shader subdivision" },
		{ "", "-lomem", "Low memory but slower lighting mode" },
		{ "", "-lowquality", "Low quality floodlight (currently breaks floodlight, do not use)" },
		{ "", "-minsamplesize <N>", "Sets minimum lightmap resolution in units/px" },
		{ "", "-nocollapse", "Do not collapse identical lightmaps" },
		{ "", "-nofastpoint", "Disable automatic fast mode for point lights" },
		{ "", "-nofloodstyles", "Disable floodlighting on styled lightmaps" },
		{ "", "-nodeluxe, -nodeluxemap", "Disable deluxemapping" },
		{ "", "-nogrid", "Disable grid light calculation (makes all entities fullbright)" },
		{ "", "-nolightmap", "Disables lightmap generation for all surfaces, making them vertex lit" },
		{ "", "-nolightmapsearch", "Do not optimize lightmap packing for GPU memory usage (as doing so costs fps)" },
		{ "", "-nosRGB", "Disable sRGB color for lightmaps, textures and light colors" },
		{ "", "-nosRGBcolor", "Disable sRGB color for light colors" },
		{ "", "-nosRGBlight", "Disable sRGB color for lightmaps" },
		{ "", "-nosRGBtex", "Disable sRGB color for textures (for sampling radiosity)" },
		{ "", "-normalmap", "Color the lightmaps according to the direction of the surface normal (same as `-debugnormals`)" },
		{ "", "-nostyle, -nostyles", "Disable support for light styles" },
		{ "", "-nosurf", "Disable tracing against surfaces (only uses BSP nodes then)" },
		{ "", "-notrace", "Disable shadow occlusion" },
		{ "", "-patchshadows", "Cast shadows from patches" },
		{ "", "-point <F>, -pointscale <F>", "Scaling factor for point lights (light entities)" },
		{ "", "-q3, -invsqatten", "Use nonlinear falloff curve by default (like Q3A)" },
		{ "", "-randomsamples", "Use random luxels selection with `-samples`" },
		{ "", "-rawlightmapsizelimit <N>", "Limits raw lightmap size" },
		{ "", "-samples <N>", "Adaptive supersampling quality" },
		{ "", "-samplescale <N>", "Scales all lightmap resolutions" },
		{ "", "-samplesize <N>", "Sets default lightmap resolution in units/px" },
		{ "", "-samplessearchboxsize  <N>", "Multiplies search box size of `-samples`" },
		{ "", "-scale <F>", "Scaling factor for all light types" },
		{ "", "-shade", "Enable phong shading at default shade angle" },
		{ "", "-shadeangle <F>", "Enable phong shading with specified angle" },
		{ "", "-sky <F>, -skyscale <F>", "Scaling factor for sky and sun light" },
		{ "", "-spherical <F>, -sphericalscale <F>", "Scaling factor for spherical point lights" },
		{ "", "-spot <F>, -spotscale <F>", "Scaling factor for spot point lights" },
		{ "", "-srffile <filename.srf>", "Surface file to read" },
		{ "", "-sRGB", "Enable sRGB color for lightmaps, textures and light colors" },
		{ "", "-sRGBcolor", "Enable sRGB color for light colors" },
		{ "", "-sRGBlight", "Enable sRGB color for lightmaps" },
		{ "", "-sRGBtex", "Enable sRGB color for textures (for sampling radiosity)" },
		{ "", "-style, -styles", "Enable support for light styles" },
		{ "", "-sunonly", "Only compute sun light" },
		{ "", "-super <N>, -supersample <N>", "Ordered grid supersampling quality" },
		{ "", "-thresh <F>", "Triangle subdivision threshold" },
		{ "", "-trianglecheck", "Nudges luxels to their original triangle" },
		{ "", "-trisoup", "Convert brush faces to triangle soup" },
		{ "", "-wolf, -linearatten", "Use linear falloff curve by default (like W:ET)" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printMinimap() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };

	tb.addRows({
		"Generating Minimap",
		"Creates a minimap of the BSP, by default writes to `mapname.tga`",
		"",
		"Usage: -minimap [options...] <filename.bsp>",
		"",
		"Options:",
		{ "", "-autolevel", "Enable automatic height based brightness/contrast adjustment" },
		{ "", "-black", "Write the minimap as a black-on-transparency RGBA32 image" },
		{ "", "-boost <F>", "Sets the contrast boost value (higher values make a brighter image); contrast boost is somewhat similar to gamma, but continuous even at zero" },
		{ "", "-border <F>", "Sets the amount of border pixels relative to the total image size" },
		{ "", "-gray", "Write the minimap as a white-on-black GRAY8 image" },
		{ "", "-keepaspect", "Ensure the aspect ratio is kept (the minimap is then letterboxed to keep aspect)" },
		{ "", "-minmax <xmin ymin zmin xmax ymax zmax>", "Forces specific map dimensions (note: the minimap actually uses these dimensions, scaled to the target size while keeping aspect with centering, and 1/64 of border appended to all sides)" },
		{ "", "-noautolevel", "Disable automatic height based brightness/contrast adjustment" },
		{ "", "-nokeepaspect", "Do not ensure the aspect ratio is kept (makes it easier to use the image in your code, but looks bad together with sharpening)" },
		{ "", "-o <filename.tga>", "Sets the output file name" },
		{ "", "-random <N>", "Sets the randomized supersampling count (cannot be combined with `-samples`)" },
		{ "", "-samples <N>", "Sets the ordered supersampling count (cannot be combined with `-random`)" },
		{ "", "-sharpen <F>", "Sets the sharpening coefficient" },
		{ "", "-size <N>", "Sets the width and height of the output image" },
		{ "", "-white", "Write the minimap as a white-on-transparency RGBA32 image" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printBspScale() const
{
	TableBuilder tb{ 7, optMaxNameWidth, optMaxDescWidth };
	tb.addRows({
		"BSP Scale",
		"Scales BSP file",
		"",
		{ "Usage:", "-scale <S filename.bsp>", "Scale uniformly" },
		{ "", "-scale <SX SY SZ filename.bsp>", "Scale non-uniformly" },
		{ "", "-scale -tex <S filename.bsp>", "Scale uniformly without texture lock" },
		{ "", "-scale -tex <SX SY SZ filename.bsp>", "Scale non-uniformly without texture lock" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printStages() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };

	tb.addRows({
		"Stages:",
		{ "", "-bsp", "BSP Stage" },
		{ "", "-vis", "VIS Stage" },
		{ "", "-light", "Light Stage" },
		{ "", "-analyze", "Analyzing BSP-like file structure" },
		{ "", "-scale", "Scaling" },
		{ "", "-convert", "Converting & Decompiling" },
		{ "", "-export", "Exporting lightmaps" },
		{ "", "-exportents", "Exporting entities" },
		{ "", "-fixaas", "Fixing AAS checksum" },
		{ "", "-info", "Get info about BSP file" },
		{ "", "-import", "Importing lightmaps" },
		{ "", "-minimap", "Generating minimap" },
	});

	std::cout << tb;
}

void CompilerHelpPrinter::printVisCompile() const
{
	TableBuilder tb{ optIndentLevel, optMaxNameWidth, optMaxDescWidth };
	tb.addRows({
		"VIS Stage",
		"Calcuates visibility portals",
		"",
		"Usage: -vis [options...] <filename.map>",
		"",
		"Options:",
		{ "", "-fast", "Very fast and crude vis calculation" },
		{ "", "-hint", "Faster but still decent vis calculation" },
		{ "", "-merge", "Faster but still okay vis calculation" },
		{ "", "-mergeportals", "The less crude half of `-merge`, makes vis sometimes much faster but doesn't hurt fps usually" },
		{ "", "-nopassage", "Just use PortalFlow vis (usually less fps)" },
		{ "", "-nosort", "Do not sort the portals before calculating vis (usually slower)" },
		{ "", "-passageOnly", "Just use PassageFlow vis (usually less fps)" },
		{ "", "-prtfile <filename.prt>", "Portal file to read" },
		{ "", "-saveprt", "Keep the Portal file after running vis (so you can run vis again)" },
	});

	std::cout << tb;
}