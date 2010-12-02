/* help messages */

#include "helpmsg.h"

char help_bindings_page[] = 
"                       Image Navigation\n\n"
"Middle click or space bar          Pan cursor\n"
"'='                                Zoom in around cursor\n"
"'-'                                Zoom out\n"
"Left button drag left/right        Adjust brightness\n"
"Left button drag up/down           Adjust contrast\n"
"0                                  Auto scale intesity\n"
"9                                  Scale Min-Max\n"
"1-8                                Auto scale with different intensity spans\n"
"                                   1 is sharpest, 8 is dullest\n"
"\n"
"                       Selection\n\n"
"Left click on an object            Select object (and deselect all others)\n"
"Shift-left click on an object      Add to selection\n"
"Ctrl-left click on a star image    Mark star (if not too faint)\n"
"Left click on image:               Show local image statistics\n"
"\n"
"                       Menus\n\n"
"Right click on image               Pop-up the main menu\n"
"Right click on an object           Pop-up the star menu\n"
"\n"
"Many useful commands have keyboard accelerators; they are displayed\n"
"in the menus.\n"
;

char help_usage_page[] = 
"\ngcx version "VERSION"\n"
"\nusage: gcx [options] [<fits file> ...]\n\n"
"                       General options:\n"
"-h, --help                         Print command line options\n"
"    --help-all                     Print all the on-line help on stdout\n"
"    --version                      Print program version\n"
"-D, --debug <level>                Set debug level to <level>; 0=quiet, 4=noisy\n"
"-o, --output <file_name>           Specify output file name for import, convert\n"
"                                     and frame operations\n"
"-r, --rcfile <params_file>         Load parameters file\n"
"-S, --set <option>=<value>         Set an option overriding the parameters file\n"
"-i, --interactive                  Display frames as they are being processed\n"
"\n"
"       Observation scripting, photometry and file conversion options:\n"
"-p, --recipe <recipe_file>         Load recipe file (searches rcp_path)\n"
"-P, --phot-run <recipe_file>       Load recipe file and run photometry\n"
"                                     in batch mode. Report in native\n"
"                                     format.\n"
"-V, --phot-run-aavso <recipe_file> Load recipe file and run photometry\n"
"                                     in batch mode. Report in AAVSO format.\n"
"\n"
"  If <recipe_file> is set to one of the following three special tokens,\n"
"  the recipe will change depeding on information in the frame header:\n"
"        _TYHCO_ will create a recipe on-the-fly;\n"
"        _OBJECT_ will search the recipe path for a file with the same\n"
"                   name as the object in the frame (ending in .rcp);\n"
"        _AUTO_ will search for a recipe by object name, and if that\n"
"                   is not found, create a tycho one.\n\n"
"    --import <catalog name>        Convert a tabular catalog file to the gcx\n"
"                                     Lisp-like format. Reads stdin.\n"
"                                     Current table formats are:\n"
"                                     gcvs, gcvs-pos, landolt, henden, sumner\n"
"    --merge <recipe_file>          Merge a new recipe file over the one loaded\n"
"                                     with the --recipe option. Checks are made\n"
"                                     for either positional or name duplicates.\n"
"                                     Only stars brighter than mag_limit are\n"
"                                     merged.\n" 
"    --set-target                   Specify a target object to be merged into a\n"
"                                     recipe file. It will also set the recipe\n" 
"                                     object, ra and dec fields.\n"
"    --make-tycho-rcp <radius>      Create a recipe file for the object specified\n"
"                                     with --object using tycho2 stars in a box\n"
"                                     radius arcminutes around the object\n"
//"    --convert-rcp <recipe_file>    Convert a recipe to the new format\n"
//"                                     If an output file name is not specified\n"
//"                                     (with the '-o' argument), stdout is used\n"
//"                                     If the file argument is '-', stdin is read\n"
"    --rcp-to-aavso <recipe_file>   Conevrt a recipe file to the aavso db\n"
"                                     (tab-delimited) format\n"
"                                     If the file argument is '-', stdin is read\n"
"                                     The recipe comment and star comment fields\n"
"                                     are interpreted to get some db fields.\n"
"                                     see the --help-all for more info\n"
"-T, --rep-to-table <report_file>   Convert a report file to tabular format\n"
"                                     If an output file name is not specified\n"
"                                     (with the '-o' argument), stdout is used\n"
"                                     If the file argument is '-', stdin is read\n"
"-O, --obsfile <obs_file>           Load/run obs file (searches obs_path)\n"
"-n, --to-pnm                       Convert a fits file to 8-bit pnm\n"
"                                     If an output file name is not specified\n"
"                                     (with the '-o' argument), stdout is used\n"
"-j, --object                       Specify a target object (useful for setting\n"
"                                     an initial wcs\n"
"    --mag-limit                    Set a magnitude limit for the output of\n"
"                                     import and merge commands.\n"
"\n"
"                    CCD Reduction Options\n"
"-d, --dark <dark_frame>            Set the dark frame / do dark subtraction\n"
"-b, --bias <bias_frame>            Set the bias frame / do bias subtraction\n"
"-f, --flat <flat_frame>            Set the flat field frame / flatfield\n"
"-G, --gaussian-blur <fwhm >        Set blur FWHM / apply Gaussian blur\n" 
"-a, --align <align_ref_frame>      Set the alignment reference frame\n"
"                                      / align frames\n"
/* "-B, --badpix <bad_pixel_file>      Set the bad pixels map file\n" */
"-A, --add-bias <bias>              Set a constant bias to add to all frames\n"
"                                      / add a bias to frames\n" 
"-M, --multiply <multiplier>        Set a constant to multiply all frames with\n" 
"                                      / multiply frames by a scalar\n" 
"                                   Multiplication is performed before addition.\n"
"-u, --update-file                  Save reduction results back to\n"
"                                     the original files\n"
"-s, --stack                        Stack the frames using the method set in\n"
"                                     the parameters file; for some methods\n"
"                                     additive background alignment is performed\n"
"-F, --superflat                    Stack the frames using an multiplicative\n"
"                                     background alignment procedure; the frames\n"
"                                     should be dark-substracted\n"
"-N, --no-reduce                    Do not run the reduction operations, just\n"
"                                     load the frame list / reduction options\n"
"-c, --demosaic                     Enable demosaicing using the method set in\n"
"                                     the parameters file;  If no color-field array\n"
"                                     is specified by the input file, the default\n"
"                                     specified in the parameters file is used\n"

"\n    When any of the CCD reduction options is set and the -i flag\n"
"    is not specified, the reduction operations are run in batch mode\n"
"    on all the supplied fits files. When no output file is specified\n"
"    or -i is set, the files are loaded into the batch processing file\n"
"    list, the reduction options set in the dialog, and the program\n"
"    starts up in gui mode\n"
;

char help_obscmd_page[] = 
"             Observation Script Commands\n\n"
"get              get and display an image without saving\n"
"dark             get and display an dark frame without saving\n"
"goto             goto <objname> [<recipe>]\n"
"                   set observation target and slew telescope\n"
"                   also load the recipe file if present\n"
"match            match frame wcs and repoint telescope to center\n"
"                   the target object \n"
"phot             run the recipe file on the current frame\n"
"ckpoint          check and correct the pointing; if too far off\n"
"                   move the telescope to center the object,\n"
"                   sync it and get another frame\n"
"save             save the current frame using an automatically\n"
"                   generated name\n"
"mget [<frames>]  get and save a number of frames\n"
"filter <name>    select filter\n"
"exp <exposure>   set exposure time in seconds for succeeding frames\n"
/*"mphot [<frames>] get, save and run photometry on a number of frames\n"*/
;

char help_rep_conv_page[] = 
"             Report Converter Format String\n\n"
"The report converter option converts the native gcx output to a\n"
"fixed-width tabular format that is easy to import in other programs\n"
"for further processing. The table's format is defined by an option\n"
"string. The option string consists of tokens separated by spaces.\n"
"There are two types of tokens: option tokens, and column tokens.\n\n"
"Options tokens set global table options when present. They can appear\n"
"anywhere in the format string.\n\n"
"tablehead        Generate a table header line containing\n"
"                   the column titles\n"
"collist          Generate a list of columns with position information\n"
"                   at the start of the output\n\n"
"res_stats        Generate a line with descriptive statistics on\n"
"                   the stars' residuals at the end of each frame."
"Column tokens specify what information gets output in each column.\n"
"The first column token corresponds to the first output column, and so\n"
"on in order. Each column token can optionally be followed by a specifier\n"
"of the form: width.precision. The width excludes a single character\n"
"spacer between the columns. Supported colum tokens are:\n\n"
"name [w]         Output the star's designator\n"
"ra [w]           Output the right ascension in h:m:s format\n"
"dra [w.p]        Output the right ascension in decimal degrees format\n"
"dec [w]          Output the declination in d:m:s format\n"
"ddec [w.p]       Output the declination in decimal degrees format\n"
"smag [w.p] \"<band>\" Output the standard magnitude with the given name\n"
"serr [w.p] \"<band>\" Output the error of the standard magnitude\n"
"                    with the given name\n"
"imag [w.p] \"<band>\" Output the instrumental magnitude with the given name\n"
"ierr [w.p] \"<band>\" Output the error of the instrumental magnitude\n"
"                    with the given name\n"
"flags [w]        Output reduction flags and the star type\n"
"observation [w]  Output the name of the observation (a synthetic name that\n"
"                   can be used to group stars reduced from the same frame\n"
"airmass [w.p]    Output the airmass of the observation\n"
"jdate [w.p]      Output the Julian date of the observation\n"
"mjd [w.p]        Output the modified Julian date of the observation\n"
"filter [w]       Output the filter name used for the observation\n"
"xc/yc [w.p]      Output the frame coordintes of the star's centroid\n"
"xerr/yerr [w.p]  Output the estimated centroiding errors\n"
"dx/dy [w.p]      Output the amount the star was moved from it's catalog\n"
"                   position when the measuring aperture was centered\n"
"residual [w.p]   Output the star's residual in the ensemble solution\n"
"stderr [w.p]     Output the star's standard error (residual divided by \n"
"                   the estimated error\n\n"
"Fields for which data is not available are left blank\n"
"\n\n"
"When converting recipies to AAVSO database format, some fields are obtained\n"
"from the recipe and star comments. Tokens of the form <token>=<value> are\n"
"searched for. The value is taken for the database field, with underscores and\n"
"minus signs converted to spaces. The following tokens are used:\n"
"\n                         Chart comment tokens:\n\n"
"d                AAVSO (Harward) designation of the main var on the chart\n"
"s                Original chart scale\n"
"t                Latest chart date (MM/YY, YYYY or YYMMDD)\n"
"n                Name of the main variable on the chart\n"
"w                Who converted the chart\n"
"p                Sequence source\n"
"\n                         Star comment tokens:\n\n"
"p                Position source\n"
"c                Comments\n"
"n                Name of variable star\n"
"i                Id of star on chart (if different from v(aavso))\n"
;
