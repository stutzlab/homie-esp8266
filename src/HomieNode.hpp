<?xml version="1.0" encoding="UTF-8"?>
<project version="4">
  <component name="CMakeRunConfigurationManager" shouldGenerate="true" assignedExecutableTargets="true" buildAllGenerated="true">
    <generated>
      <config projectName="{{project_name}}" targetName="PLATFORMIO" />
      <config projectName="{{project_name}}" targetName="{{project_name}}" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_BUILD" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_UPLOAD" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_CLEAN" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_PROGRAM" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_UPLOADFS" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_UPDATE_ALL" />
      <config projectName="{{project_name}}" targetName="PLATFORMIO_REBUILD_PROJECT_INDEX" />
      <config projectName="{{project_name}}" targetName="DEBUG" />
    </generated>
  </component>
  <component name="CMakeSettings" AUTO_RELOAD="true" GENERATION_PASS_SYSTEM_ENVIRONMENT="true">
    <ADDITIONAL_GENERATION_ENVIRONMENT>
      <envs />
    </ADDITIONAL_GENERATION_ENVIRONMENT>
  </component>
  <component name="ChangeListManager">
    <list default="true" id="ec922180-b3d3-40f1-af0b-2568113a9075" name="Default" comment="" />
    <ignored path="platformio.iws" />
    <ignored path=".idea/workspace.xml" />
    <option name="EXCLUDED_CONVERTED_TO_IGNORED" value="true" />
    <option name="TRACKING_ENABLED" value="true" />
    <option name="SHOW_DIALOG" value="false" />
    <option name="HIGHLIGHT_CONFLICTS" value="true" />
    <option name="HIGHLIGHT_NON_ACTIVE_CHANGELIST" value="false" />
    <option name="LAST_RESOLUTION" value="IGNORE" />
  </component>
  <component name="ChangesViewManager" flattened_view="true" show_ignored="false" />
  <component name="CreatePatchCommitExecutor">
    <option name="PATCH_PATH" value="" />
  </component>
  <component name="ExecutionTargetManager" SELECTED_TARGET="default_target" />
  <component name="FavoritesManager">
    <favorites_list name="{{project_name}}" />
  </component>
  <component name="FileEditorManager">
    <leaf>
      <file leaf-file-name="platformio.ini" pinned="false" current-in-tab="true">
        <entry file="file://$PROJECT_DIR$/platformio.ini"></entry>
      </file>
      % for file in src_files:
      <file leaf-file-name="file://$PROJECT_DIR$/{{file}}" pinned="false" current-in-tab="false">
        <entry file="file://$PROJECT_DIR/${{file}}"></entry>
      </file>
      % end
    </leaf>
  </component>
  <component name="JsBuildToolGruntFileManager" detection-done="true" />
  <component name="JsGulpfileManager">
    <detection-done>true</detection-done>
  </component>
  <component name="NamedScopeManager">
    <order />
  </component>
  <component name="ProjectFrameBounds">
    <op